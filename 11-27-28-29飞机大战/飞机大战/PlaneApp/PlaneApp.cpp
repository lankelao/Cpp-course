#include"PlaneApp.h"
#include"../GameConfig/GameConfig.h"
#include<time.h>
#include"../FoePlaneBox/FoePlane.h"
#include"../FoePlaneBox/FoePlaneBig.h"
#include"../FoePlaneBox/FoePlaneMid.h"
#include"../FoePlaneBox/FoePlaneSma.h"

GET_OBJECT(CPlaneApp)
CLASS_CONFIG(WND_PARAM_X,WND_PARAM_Y,WND_PARAM_WIDTH,WND_PARAM_HEIGH,WND_PARAM_TITLE)


CPlaneApp::CPlaneApp(){

}
CPlaneApp::~CPlaneApp(){

}

//case WM_CREATE: //窗口创建消息
void CPlaneApp::OnCreate(){

	srand((unsigned int)time(NULL));

	//创建定时器
	SetTimmer();

	//初始化背景
	m_back.InitBackGround(0,0,this->m_hInstance);

	m_player.InitPlayerPlan((MAPSIZE_BACKGROUND_WIDTH-MAPSIZE_PLAYERPLANE_WIDTH)/2,MAPSIZE_BACKGROUND_HEIGH-MAPSIZE_PLAYERPLANE_HEIGH,this->m_hInstance);
}

	//case WM_PAINT:  //重绘消息
void CPlaneApp::OnDraw(){
	//获取窗口DC
	PAINTSTRUCT ps = {0};
	HDC hdc = ::BeginPaint(this->m_hWnd,&ps);
	//创建缓冲DC
	HDC cacheDC = ::CreateCompatibleDC(hdc);
	HBITMAP map = ::CreateCompatibleBitmap(hdc,MAPSIZE_BACKGROUND_WIDTH,MAPSIZE_BACKGROUND_HEIGH);
	::SelectObject(cacheDC,map);
	//创建兼容性DC
	HDC compDC = ::CreateCompatibleDC(cacheDC);
//----------------------------------------------------------
	m_back.ShowBackGround(cacheDC,compDC);
	m_player.ShowPlayerPlan(cacheDC,compDC);
	m_gunBox.ShowAllGUnner(cacheDC,compDC);
	m_foePlaneBox.ShowAllFoePlane(cacheDC,compDC);
	m_foePlaneBox.ShowAllBoomPlane(cacheDC,compDC);
	BitBlt(hdc,0,0,MAPSIZE_BACKGROUND_WIDTH,MAPSIZE_BACKGROUND_HEIGH,cacheDC,0,0,SRCCOPY);
//----------------------------------------------------------
	DeleteDC(compDC);
	compDC = NULL;

	::DeleteObject(map);
	map = NULL;

	DeleteDC(cacheDC);
	cacheDC = NULL;

	::EndPaint(this->m_hWnd,&ps);
}


#define CREATE_FOEPLANE(FOEPLANE_CLASS)\
	CFoePlane *pFoe = new FOEPLANE_CLASS;\
	pFoe->InitFoePlane(this->m_hInstance);\
	m_foePlaneBox.m_lstFoe.push_back(pFoe);

	//case WM_TIMER:   //定时器，需要我们在子类中手动添加定时器并设置触发间隔
void CPlaneApp::OnGameRun(WPARAM wParam){
	switch(wParam)
	{
	case TIMER_BACKGROUND_MOVE_TIMERID://背景移动
		{
			m_back.MoveBackGround(3);
		}
		break;
	case TIMER_PLAYERPLANE_MOVE_TIMERID://玩家飞机移动
		{
			if(::GetAsyncKeyState(VK_LEFT)){
				m_player.MovePlayerPlan(VK_LEFT,PLAYERPLANE_MOVE_STEP);
			}
			if(::GetAsyncKeyState(VK_RIGHT)){
				m_player.MovePlayerPlan(VK_RIGHT,PLAYERPLANE_MOVE_STEP);
			}
			if(::GetAsyncKeyState(VK_UP)){
				m_player.MovePlayerPlan(VK_UP,PLAYERPLANE_MOVE_STEP);
			}
			if(::GetAsyncKeyState(VK_DOWN)){
				m_player.MovePlayerPlan(VK_DOWN,PLAYERPLANE_MOVE_STEP);
			}
		}
		break;

	case TIMER_GUNNER_MOVE_TIMERID://炮弹移动
		{
			m_gunBox.MoveAllGunner(GUNNER_MOVE_STEP);
		}
		break;
	case TIMER_SEND_GUNNER_TIMERID://发射炮弹
		{
			CGunner *pGun = m_player.SendGunner(this->m_hInstance);
			m_gunBox.m_lstGunner.push_back(pGun);
		}
		break;
	case TIMER_FOEBIG_CREATE_TIMERID://创建敌人大飞机
		{
			CREATE_FOEPLANE(CFoePlaneBig);
		}
		break;
	case TIMER_FOEMID_CREATE_TIMERID://创建敌人中飞机
		{
			CREATE_FOEPLANE(CFoePlaneMid);
		}
		break;
	case TIMER_FOESMA_CREATE_TIMERID://创建敌人小飞机
		{
			//CFoePlane *pFoe = new CFoePlaneSma;
			//pFoe->InitFoePlane(this->m_hInstance);

			////todo:添加到飞机盒子里
			//m_foePlaneBox.m_lstFoe.push_back(pFoe);
			CREATE_FOEPLANE(CFoePlaneSma);
		}
		break;
	case TIMER_FOEPLANE_MOVE_TIMERID://敌人飞机移动
		{
			m_foePlaneBox.MoveAllFoePlane();
		}
		break;
	case TIMER_CHECK_FOEPLANE_HIT_TIMMERID://定时检查是否撞击
		{
			bool isBoom = false;
			list<CFoePlane*>::iterator iteFoe = m_foePlaneBox.m_lstFoe.begin();
			while(iteFoe != m_foePlaneBox.m_lstFoe.end()){
//-----------------------遍历所有敌人飞机------------------------
				//判断是否撞击玩家飞机
				if((*iteFoe)->IsHitPlayer(m_player)){
					//游戏结束
					GameOver();

					return;
				}
					//判断是否撞击到炮弹
				list<CGunner*>::iterator itegun = m_gunBox.m_lstGunner.begin();
				while(itegun != m_gunBox.m_lstGunner.end()){
					if((*iteFoe)->IsHitGunner((*itegun))){//判断敌人飞机是否撞击到炮弹
						//炮弹消失
						itegun = m_gunBox.m_lstGunner.erase(itegun);
						//敌人血量减少
						(*iteFoe)->m_nBlood -= GUNNER_HURT;
						//判断血量是否为0
						if((*iteFoe)->m_nBlood<=0){
							isBoom = true;
							//移动敌人到爆炸链表
							m_foePlaneBox.m_lstBoomFoe.push_back(*iteFoe);
							//删除正常的链表
							iteFoe = m_foePlaneBox.m_lstFoe.erase(iteFoe);
						}
						break;
					}

					itegun++;
				}
//-----------------------遍历所有敌人飞机---------------------------------
				if(isBoom){
					isBoom = false;
				}else{
					iteFoe++;
				}

				}
		}
		break;
	case TIMER_CHANGE_FOEPLANE_BOOM_TIMMERID://定时切换爆炸效果
		{
			list<CFoePlane*>::iterator ite = m_foePlaneBox.m_lstBoomFoe.begin();
			while(ite != m_foePlaneBox.m_lstBoomFoe.end()){
				(*ite)->m_showId--;
				if((*ite)->m_showId < 0){
					delete (*ite);
					(*ite) = NULL;
					ite = m_foePlaneBox.m_lstBoomFoe.erase(ite);
					continue;
				}
				ite++;
			}
		}
		break;
	}	
	RECT rect = {0,0,MAPSIZE_BACKGROUND_WIDTH,MAPSIZE_BACKGROUND_HEIGH};
	::InvalidateRect(this->m_hWnd,&rect,FALSE);
}

	//case WM_KEYDOWN:  //键盘按下触发消息
void CPlaneApp::OnKeyDown(WPARAM wParam){


	//m_player.MovePlayerPlan(wParam,PLAYERPLANE_MOVE_STEP);
}

void CPlaneApp::SetTimmer(){
	//设置背景移动的定时器
	::SetTimer(this->m_hWnd,TIMER_BACKGROUND_MOVE_TIMERID,TIMER_BACKGROUND_MOVE_INTERVAL,NULL);
	//飞机移动检测定时器
	::SetTimer(this->m_hWnd,TIMER_PLAYERPLANE_MOVE_TIMERID,TIMER_PLAYERPLANE_MOVE_INTERVAL,NULL);
	//炮弹移动的定时器
	::SetTimer(this->m_hWnd,TIMER_GUNNER_MOVE_TIMERID,TIMER_GUNNER_MOVE_INTERVAL,NULL);
	//发射炮弹的定时器
	::SetTimer(this->m_hWnd,TIMER_SEND_GUNNER_TIMERID,TIMER_SEND_GUNNER_INTERVAL,NULL);
	//创建敌人大飞机
	::SetTimer(this->m_hWnd,TIMER_FOEBIG_CREATE_TIMERID,TIMER_FOEBIG_CREATE_INTERVAL,NULL);
	//创建敌人中飞机
	::SetTimer(this->m_hWnd,TIMER_FOEMID_CREATE_TIMERID,TIMER_FOEMID_CREATE_INTERVAL,NULL);
	//创建敌人小飞机
	::SetTimer(this->m_hWnd,TIMER_FOESMA_CREATE_TIMERID,TIMER_FOESMA_CREATE_INTERVAL,NULL);

	//敌人飞机移动定时器
	::SetTimer(this->m_hWnd,TIMER_FOEPLANE_MOVE_TIMERID,TIMER_FOEPLANE_MOVE_INTERVAL,NULL);
	//定时检查是否撞击
	::SetTimer(this->m_hWnd,TIMER_CHECK_FOEPLANE_HIT_TIMMERID,TIMER_CHECK_FOEPLANE_HIT_INTERVAL,NULL);
	//切换爆炸效果
	::SetTimer(this->m_hWnd,TIMER_CHANGE_FOEPLANE_BOOM_TIMMERID,TIMER_CHANGE_FOEPLANE_BOOM_INTERVAL,NULL);

}

void CPlaneApp::GameOver(){
	//杀死定时器
	//设置背景移动的定时器
	::KillTimer(this->m_hWnd,TIMER_BACKGROUND_MOVE_TIMERID);
	//飞机移动检测定时器
	::KillTimer(this->m_hWnd,TIMER_PLAYERPLANE_MOVE_TIMERID);
	//炮弹移动的定时器
	::KillTimer(this->m_hWnd,TIMER_GUNNER_MOVE_TIMERID);
	//发射炮弹的定时器
	::KillTimer(this->m_hWnd,TIMER_SEND_GUNNER_TIMERID);
	//创建敌人大飞机
	::KillTimer(this->m_hWnd,TIMER_FOEBIG_CREATE_TIMERID);
	//创建敌人中飞机
	::KillTimer(this->m_hWnd,TIMER_FOEMID_CREATE_TIMERID);
	//创建敌人小飞机
	::KillTimer(this->m_hWnd,TIMER_FOESMA_CREATE_TIMERID);

	//敌人飞机移动定时器
	::KillTimer(this->m_hWnd,TIMER_FOEPLANE_MOVE_TIMERID);
	//定时检查是否撞击
	::KillTimer(this->m_hWnd,TIMER_CHECK_FOEPLANE_HIT_TIMMERID);
	//切换爆炸效果
	::KillTimer(this->m_hWnd,TIMER_CHANGE_FOEPLANE_BOOM_TIMMERID);

	//提示GameOver
	::MessageBox(this->m_hWnd,"GameOver~~","提示",MB_OK);
	//发送程序退出消息
	PostMessage(this->m_hWnd,WM_DESTROY,0,0);
}
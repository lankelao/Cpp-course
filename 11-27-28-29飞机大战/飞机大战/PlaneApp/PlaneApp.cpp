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

//case WM_CREATE: //���ڴ�����Ϣ
void CPlaneApp::OnCreate(){

	srand((unsigned int)time(NULL));

	//������ʱ��
	SetTimmer();

	//��ʼ������
	m_back.InitBackGround(0,0,this->m_hInstance);

	m_player.InitPlayerPlan((MAPSIZE_BACKGROUND_WIDTH-MAPSIZE_PLAYERPLANE_WIDTH)/2,MAPSIZE_BACKGROUND_HEIGH-MAPSIZE_PLAYERPLANE_HEIGH,this->m_hInstance);
}

	//case WM_PAINT:  //�ػ���Ϣ
void CPlaneApp::OnDraw(){
	//��ȡ����DC
	PAINTSTRUCT ps = {0};
	HDC hdc = ::BeginPaint(this->m_hWnd,&ps);
	//��������DC
	HDC cacheDC = ::CreateCompatibleDC(hdc);
	HBITMAP map = ::CreateCompatibleBitmap(hdc,MAPSIZE_BACKGROUND_WIDTH,MAPSIZE_BACKGROUND_HEIGH);
	::SelectObject(cacheDC,map);
	//����������DC
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

	//case WM_TIMER:   //��ʱ������Ҫ�������������ֶ���Ӷ�ʱ�������ô������
void CPlaneApp::OnGameRun(WPARAM wParam){
	switch(wParam)
	{
	case TIMER_BACKGROUND_MOVE_TIMERID://�����ƶ�
		{
			m_back.MoveBackGround(3);
		}
		break;
	case TIMER_PLAYERPLANE_MOVE_TIMERID://��ҷɻ��ƶ�
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

	case TIMER_GUNNER_MOVE_TIMERID://�ڵ��ƶ�
		{
			m_gunBox.MoveAllGunner(GUNNER_MOVE_STEP);
		}
		break;
	case TIMER_SEND_GUNNER_TIMERID://�����ڵ�
		{
			CGunner *pGun = m_player.SendGunner(this->m_hInstance);
			m_gunBox.m_lstGunner.push_back(pGun);
		}
		break;
	case TIMER_FOEBIG_CREATE_TIMERID://�������˴�ɻ�
		{
			CREATE_FOEPLANE(CFoePlaneBig);
		}
		break;
	case TIMER_FOEMID_CREATE_TIMERID://���������зɻ�
		{
			CREATE_FOEPLANE(CFoePlaneMid);
		}
		break;
	case TIMER_FOESMA_CREATE_TIMERID://��������С�ɻ�
		{
			//CFoePlane *pFoe = new CFoePlaneSma;
			//pFoe->InitFoePlane(this->m_hInstance);

			////todo:��ӵ��ɻ�������
			//m_foePlaneBox.m_lstFoe.push_back(pFoe);
			CREATE_FOEPLANE(CFoePlaneSma);
		}
		break;
	case TIMER_FOEPLANE_MOVE_TIMERID://���˷ɻ��ƶ�
		{
			m_foePlaneBox.MoveAllFoePlane();
		}
		break;
	case TIMER_CHECK_FOEPLANE_HIT_TIMMERID://��ʱ����Ƿ�ײ��
		{
			bool isBoom = false;
			list<CFoePlane*>::iterator iteFoe = m_foePlaneBox.m_lstFoe.begin();
			while(iteFoe != m_foePlaneBox.m_lstFoe.end()){
//-----------------------�������е��˷ɻ�------------------------
				//�ж��Ƿ�ײ����ҷɻ�
				if((*iteFoe)->IsHitPlayer(m_player)){
					//��Ϸ����
					GameOver();

					return;
				}
					//�ж��Ƿ�ײ�����ڵ�
				list<CGunner*>::iterator itegun = m_gunBox.m_lstGunner.begin();
				while(itegun != m_gunBox.m_lstGunner.end()){
					if((*iteFoe)->IsHitGunner((*itegun))){//�жϵ��˷ɻ��Ƿ�ײ�����ڵ�
						//�ڵ���ʧ
						itegun = m_gunBox.m_lstGunner.erase(itegun);
						//����Ѫ������
						(*iteFoe)->m_nBlood -= GUNNER_HURT;
						//�ж�Ѫ���Ƿ�Ϊ0
						if((*iteFoe)->m_nBlood<=0){
							isBoom = true;
							//�ƶ����˵���ը����
							m_foePlaneBox.m_lstBoomFoe.push_back(*iteFoe);
							//ɾ������������
							iteFoe = m_foePlaneBox.m_lstFoe.erase(iteFoe);
						}
						break;
					}

					itegun++;
				}
//-----------------------�������е��˷ɻ�---------------------------------
				if(isBoom){
					isBoom = false;
				}else{
					iteFoe++;
				}

				}
		}
		break;
	case TIMER_CHANGE_FOEPLANE_BOOM_TIMMERID://��ʱ�л���ըЧ��
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

	//case WM_KEYDOWN:  //���̰��´�����Ϣ
void CPlaneApp::OnKeyDown(WPARAM wParam){


	//m_player.MovePlayerPlan(wParam,PLAYERPLANE_MOVE_STEP);
}

void CPlaneApp::SetTimmer(){
	//���ñ����ƶ��Ķ�ʱ��
	::SetTimer(this->m_hWnd,TIMER_BACKGROUND_MOVE_TIMERID,TIMER_BACKGROUND_MOVE_INTERVAL,NULL);
	//�ɻ��ƶ���ⶨʱ��
	::SetTimer(this->m_hWnd,TIMER_PLAYERPLANE_MOVE_TIMERID,TIMER_PLAYERPLANE_MOVE_INTERVAL,NULL);
	//�ڵ��ƶ��Ķ�ʱ��
	::SetTimer(this->m_hWnd,TIMER_GUNNER_MOVE_TIMERID,TIMER_GUNNER_MOVE_INTERVAL,NULL);
	//�����ڵ��Ķ�ʱ��
	::SetTimer(this->m_hWnd,TIMER_SEND_GUNNER_TIMERID,TIMER_SEND_GUNNER_INTERVAL,NULL);
	//�������˴�ɻ�
	::SetTimer(this->m_hWnd,TIMER_FOEBIG_CREATE_TIMERID,TIMER_FOEBIG_CREATE_INTERVAL,NULL);
	//���������зɻ�
	::SetTimer(this->m_hWnd,TIMER_FOEMID_CREATE_TIMERID,TIMER_FOEMID_CREATE_INTERVAL,NULL);
	//��������С�ɻ�
	::SetTimer(this->m_hWnd,TIMER_FOESMA_CREATE_TIMERID,TIMER_FOESMA_CREATE_INTERVAL,NULL);

	//���˷ɻ��ƶ���ʱ��
	::SetTimer(this->m_hWnd,TIMER_FOEPLANE_MOVE_TIMERID,TIMER_FOEPLANE_MOVE_INTERVAL,NULL);
	//��ʱ����Ƿ�ײ��
	::SetTimer(this->m_hWnd,TIMER_CHECK_FOEPLANE_HIT_TIMMERID,TIMER_CHECK_FOEPLANE_HIT_INTERVAL,NULL);
	//�л���ըЧ��
	::SetTimer(this->m_hWnd,TIMER_CHANGE_FOEPLANE_BOOM_TIMMERID,TIMER_CHANGE_FOEPLANE_BOOM_INTERVAL,NULL);

}

void CPlaneApp::GameOver(){
	//ɱ����ʱ��
	//���ñ����ƶ��Ķ�ʱ��
	::KillTimer(this->m_hWnd,TIMER_BACKGROUND_MOVE_TIMERID);
	//�ɻ��ƶ���ⶨʱ��
	::KillTimer(this->m_hWnd,TIMER_PLAYERPLANE_MOVE_TIMERID);
	//�ڵ��ƶ��Ķ�ʱ��
	::KillTimer(this->m_hWnd,TIMER_GUNNER_MOVE_TIMERID);
	//�����ڵ��Ķ�ʱ��
	::KillTimer(this->m_hWnd,TIMER_SEND_GUNNER_TIMERID);
	//�������˴�ɻ�
	::KillTimer(this->m_hWnd,TIMER_FOEBIG_CREATE_TIMERID);
	//���������зɻ�
	::KillTimer(this->m_hWnd,TIMER_FOEMID_CREATE_TIMERID);
	//��������С�ɻ�
	::KillTimer(this->m_hWnd,TIMER_FOESMA_CREATE_TIMERID);

	//���˷ɻ��ƶ���ʱ��
	::KillTimer(this->m_hWnd,TIMER_FOEPLANE_MOVE_TIMERID);
	//��ʱ����Ƿ�ײ��
	::KillTimer(this->m_hWnd,TIMER_CHECK_FOEPLANE_HIT_TIMMERID);
	//�л���ըЧ��
	::KillTimer(this->m_hWnd,TIMER_CHANGE_FOEPLANE_BOOM_TIMMERID);

	//��ʾGameOver
	::MessageBox(this->m_hWnd,"GameOver~~","��ʾ",MB_OK);
	//���ͳ����˳���Ϣ
	PostMessage(this->m_hWnd,WM_DESTROY,0,0);
}
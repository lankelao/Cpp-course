#include"PlayerPlane.h"
#include"../res/resource.h"
#include"../GameConfig/GameConfig.h"
#include"../GunnerBox/Gunner.h"

CPlayerPlane::CPlayerPlane(){
	m_player = NULL;
	m_nx = 0;
	m_ny = 0;
}
CPlayerPlane::~CPlayerPlane(){
	::DeleteObject(m_player);
	m_player = NULL;
	m_nx = 0;
	m_ny = 0;
}

void CPlayerPlane::InitPlayerPlan(int x, int y, HINSTANCE hIns){
	m_nx = x;
	m_ny = y;
	m_player = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_PLAYERPLANE));
}
void CPlayerPlane::ShowPlayerPlan(HDC hdc, HDC compHdc){
	::SelectObject(compHdc,m_player);
	::BitBlt(hdc,m_nx,m_ny,MAPSIZE_PLAYERPLANE_WIDTH,MAPSIZE_PLAYERPLANE_HEIGH,compHdc,0,0,SRCAND);

}
void CPlayerPlane::MovePlayerPlan(int direct, int step){
	switch (direct)
	{
	case VK_LEFT:
		{
			if(m_nx-step<=0){
				m_nx = 0;
			}else{
				m_nx-=step;
			}
		}
		break;
	case VK_RIGHT:
		{
			if(m_nx+step>=(MAPSIZE_BACKGROUND_WIDTH-MAPSIZE_PLAYERPLANE_WIDTH)){
				m_nx = MAPSIZE_BACKGROUND_WIDTH-MAPSIZE_PLAYERPLANE_WIDTH;
			}else{
				m_nx+=step;
			}
		}
		break;
	case VK_UP:
		{
			if(m_ny-step<=0){
				m_ny = 0;
			}else{
				m_ny-=step;
			}
		}
		break;
	case VK_DOWN:
		{
			if(m_ny+step>=(MAPSIZE_BACKGROUND_HEIGH-MAPSIZE_PLAYERPLANE_HEIGH)){
				m_ny = MAPSIZE_BACKGROUND_HEIGH-MAPSIZE_PLAYERPLANE_HEIGH;
			}else{
				m_ny+=step;
			}
		}
		break;
	}
}
CGunner *CPlayerPlane::SendGunner(HINSTANCE hIns){
	CGunner*pGun = new CGunner;
	pGun->InitGunner((m_nx+(MAPSIZE_PLAYERPLANE_WIDTH-MAPSIZE_GUNNER_WIDTH)/2),
		m_ny-MAPSIZE_GUNNER_HEIGH,hIns);

	return pGun;
}
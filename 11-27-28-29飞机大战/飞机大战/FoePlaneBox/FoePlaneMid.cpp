#include"FoePlaneMid.h"
#include"../res/resource.h"
#include"../GameConfig/GameConfig.h"
CFoePlaneMid::CFoePlaneMid(){

}
CFoePlaneMid::~CFoePlaneMid(){

}
void CFoePlaneMid::InitFoePlane(HINSTANCE hIns){
	m_foePlane = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_FOEPLANEMID));
	m_nBlood = BLOOD_FOEPLANEMID;
	m_nx = rand()%(MAPSIZE_BACKGROUND_WIDTH-MAPSIZE_FOEPLANEMID_WIDTH+1);
	m_ny = -MAPSIZE_FOEPLANEMID_HEIGH;
	m_showId = 2;
}
void CFoePlaneMid::ShowFoePlane(HDC hdc,HDC compHdc){
	::SelectObject(compHdc,m_foePlane);
	::BitBlt(hdc,m_nx,m_ny,MAPSIZE_FOEPLANEMID_WIDTH,MAPSIZE_FOEPLANEMID_HEIGH,compHdc,0,(2-m_showId)*MAPSIZE_FOEPLANEMID_HEIGH,SRCAND);
}

BOOL CFoePlaneMid::IsHitGunner(CGunner *pGun){
	int x = pGun->m_nx+MAPSIZE_GUNNER_WIDTH/2;
	if(m_nx<=x && x<=m_nx+MAPSIZE_FOEPLANEMID_WIDTH && m_ny<=pGun->m_ny && pGun->m_ny<=m_ny+MAPSIZE_FOEPLANEMID_HEIGH){
		return TRUE;
	}
	return FALSE;
} 
BOOL CFoePlaneMid::IsHitPlayer(CPlayerPlane &player){
	int x1 = player.m_nx+MAPSIZE_PLAYERPLANE_WIDTH/2;
	if(m_nx<=x1 && x1<=m_nx+MAPSIZE_FOEPLANEMID_WIDTH && m_ny<=player.m_ny && player.m_ny<=m_ny+MAPSIZE_FOEPLANEMID_HEIGH){
		return TRUE;
	}
	int y1 = player.m_ny+MAPSIZE_PLAYERPLANE_HEIGH*2/3;
	if(m_nx<=player.m_nx && player.m_nx<=m_nx+MAPSIZE_FOEPLANEMID_WIDTH && m_ny<=y1 && y1<=m_ny+MAPSIZE_FOEPLANEMID_HEIGH){
		return TRUE;
	}
	int x2 = player.m_nx+MAPSIZE_PLAYERPLANE_WIDTH;
	if(m_nx<=x2&& x2<=m_nx+MAPSIZE_FOEPLANEMID_WIDTH && m_ny<=y1 && y1<=m_ny+MAPSIZE_FOEPLANEMID_HEIGH){
		return TRUE;
	}
	return FALSE;
}
#include"FoePlaneBig.h"
#include"../res/resource.h"
#include"../GameConfig/GameConfig.h"
CFoePlaneBig::CFoePlaneBig(){

}
CFoePlaneBig::~CFoePlaneBig(){

}
void CFoePlaneBig::InitFoePlane(HINSTANCE hIns){
	m_foePlane = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_FOEPLANEBIG));
	m_nBlood = BLOOD_FOEPLANEBIG;
	m_nx = rand()%(MAPSIZE_BACKGROUND_WIDTH-MAPSIZE_FOEPLANEBIG_WIDTH+1);
	m_ny = -MAPSIZE_FOEPLANEBIG_HEIGH;
	m_showId = 3;
}
void CFoePlaneBig::ShowFoePlane(HDC hdc,HDC compHdc){
	::SelectObject(compHdc,m_foePlane);
	::BitBlt(hdc,m_nx,m_ny,MAPSIZE_FOEPLANEBIG_WIDTH,MAPSIZE_FOEPLANEBIG_HEIGH,compHdc,0,(3-m_showId)*MAPSIZE_FOEPLANEBIG_HEIGH,SRCAND);
}

BOOL CFoePlaneBig::IsHitGunner(CGunner *pGun){
	int x = pGun->m_nx+MAPSIZE_GUNNER_WIDTH/2;
	if(m_nx<=x && x<=m_nx+MAPSIZE_FOEPLANEBIG_WIDTH && m_ny<=pGun->m_ny && pGun->m_ny<=m_ny+MAPSIZE_FOEPLANEBIG_HEIGH){
		return TRUE;
	}
	return FALSE;
} 
BOOL CFoePlaneBig::IsHitPlayer(CPlayerPlane &player){
	int x1 = player.m_nx+MAPSIZE_PLAYERPLANE_WIDTH/2;
	if(m_nx<=x1 && x1<=m_nx+MAPSIZE_FOEPLANEBIG_WIDTH && m_ny<=player.m_ny && player.m_ny<=m_ny+MAPSIZE_FOEPLANEBIG_HEIGH){
		return TRUE;
	}
	int y1 = player.m_ny+MAPSIZE_PLAYERPLANE_HEIGH*2/3;
	if(m_nx<=player.m_nx && player.m_nx<=m_nx+MAPSIZE_FOEPLANEBIG_WIDTH && m_ny<=y1 && y1<=m_ny+MAPSIZE_FOEPLANEBIG_HEIGH){
		return TRUE;
	}
	int x2 = player.m_nx+MAPSIZE_PLAYERPLANE_WIDTH;
	if(m_nx<=x2&& x2<=m_nx+MAPSIZE_FOEPLANEBIG_WIDTH && m_ny<=y1 && y1<=m_ny+MAPSIZE_FOEPLANEBIG_HEIGH){
		return TRUE;
	}
	return FALSE;
}
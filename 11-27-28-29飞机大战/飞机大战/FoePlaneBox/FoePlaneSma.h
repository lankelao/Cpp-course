#pragma once
#include"FoePlane.h"

class CFoePlaneSma:public CFoePlane{
public:
	CFoePlaneSma();
	~CFoePlaneSma();
public:
	virtual void InitFoePlane(HINSTANCE hIns);
	virtual void ShowFoePlane(HDC hdc,HDC compHdc);
	virtual BOOL IsHitPlayer(CPlayerPlane &player);
	virtual BOOL IsHitGunner(CGunner *pGun);
};
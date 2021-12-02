#pragma once
#include<Windows.h>
#include"../GunnerBox/Gunner.h"

class CPlayerPlane{
public:
	HBITMAP m_player;
	int m_nx;
	int m_ny;
public:
	CPlayerPlane();
	~CPlayerPlane();
public:
	void InitPlayerPlan(int x, int y, HINSTANCE hIns);
	void ShowPlayerPlan(HDC hdc, HDC compHdc);
	void MovePlayerPlan(int direct, int step);
	CGunner *SendGunner(HINSTANCE hIns);
};



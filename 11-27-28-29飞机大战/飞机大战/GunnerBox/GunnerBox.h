#pragma once
#include<list>
using namespace std;
#include"Gunner.h"


class CGunnerBox{
public:
	list<CGunner*>m_lstGunner;
public:
	CGunnerBox();
	~CGunnerBox();
public:
	void MoveAllGunner(int step);
	void ShowAllGUnner(HDC hdc, HDC compHdc);
};
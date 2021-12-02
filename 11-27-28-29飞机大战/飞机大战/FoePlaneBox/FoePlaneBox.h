#pragma once
#include<Windows.h>
#include<list>
#include"FoePlane.h"
using namespace std;

class CFoePlaneBox{
public:
	list<CFoePlane*>m_lstBoomFoe;
	list<CFoePlane*>m_lstFoe;
public:
	CFoePlaneBox();
	~CFoePlaneBox();
public:
	void ShowAllFoePlane(HDC hdc, HDC compHdc);
	void MoveAllFoePlane();
	void ShowAllBoomPlane(HDC hdc, HDC compHdc);
};
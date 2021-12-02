#include"FoePlaneBox.h"
#include<typeinfo>
#include"FoePlaneBig.h"
#include"FoePlaneMid.h"
#include"FoePlaneSma.h"
#include"../GameConfig/GameConfig.h"


#define RANGE_DELETE_FOEPLANE(FOEPLANE_LIST)\
	list<CFoePlane*>::iterator ite##FOEPLANE_LIST = FOEPLANE_LIST.begin();\
	while(ite##FOEPLANE_LIST != FOEPLANE_LIST.end()){\
		delete *(ite##FOEPLANE_LIST);\
		*(ite##FOEPLANE_LIST) = NULL;\
		ite##FOEPLANE_LIST++;\
	}\
	FOEPLANE_LIST.clear();


CFoePlaneBox::CFoePlaneBox(){
	m_lstBoomFoe.clear();
	m_lstFoe.clear();
}

CFoePlaneBox::~CFoePlaneBox(){
	RANGE_DELETE_FOEPLANE(m_lstFoe);
	RANGE_DELETE_FOEPLANE(m_lstBoomFoe);
}

void CFoePlaneBox::ShowAllFoePlane(HDC hdc, HDC compHdc){
	list<CFoePlane*>::iterator ite = m_lstFoe.begin();
	while(ite != m_lstFoe.end()){
		//显示所有敌人飞机
		(*ite)->ShowFoePlane(hdc,compHdc);

		ite++;
	}
}
void CFoePlaneBox::MoveAllFoePlane(){
	list<CFoePlane*>::iterator ite = m_lstFoe.begin();
	while(ite != m_lstFoe.end()){
		//RTTI  运行时类型识别
//----------------------------------------------------------------------
		const type_info &ti = typeid(CFoePlaneSma);
		const char *pName = ti.name();


//----------------------------------------------------------------------

		if(typeid(*(*ite)) == typeid(CFoePlaneSma)){//小飞机
			(*ite)->MoveFoePlane(FOESMA_MOVE_STEP);
		}else if(typeid(*(*ite)) == typeid(CFoePlaneMid)){//中飞机
			(*ite)->MoveFoePlane(FOEMID_MOVE_STEP);
		}else if(typeid(*(*ite)) == typeid(CFoePlaneBig)){//大飞机
			(*ite)->MoveFoePlane(FOEBIG_MOVE_STEP);
		}
		//判断是否出界
		if((*ite)->m_ny > MAPSIZE_BACKGROUND_HEIGH){
			ite = m_lstFoe.erase(ite);
			continue;
		}
		ite++;
	}
}
void CFoePlaneBox::ShowAllBoomPlane(HDC hdc, HDC compHdc){
	list<CFoePlane*>::iterator ite = m_lstBoomFoe.begin();
	while(ite != m_lstBoomFoe.end()){

		(*ite)->ShowFoePlane(hdc,compHdc);

		ite++;
	}
}
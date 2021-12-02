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
		//��ʾ���е��˷ɻ�
		(*ite)->ShowFoePlane(hdc,compHdc);

		ite++;
	}
}
void CFoePlaneBox::MoveAllFoePlane(){
	list<CFoePlane*>::iterator ite = m_lstFoe.begin();
	while(ite != m_lstFoe.end()){
		//RTTI  ����ʱ����ʶ��
//----------------------------------------------------------------------
		const type_info &ti = typeid(CFoePlaneSma);
		const char *pName = ti.name();


//----------------------------------------------------------------------

		if(typeid(*(*ite)) == typeid(CFoePlaneSma)){//С�ɻ�
			(*ite)->MoveFoePlane(FOESMA_MOVE_STEP);
		}else if(typeid(*(*ite)) == typeid(CFoePlaneMid)){//�зɻ�
			(*ite)->MoveFoePlane(FOEMID_MOVE_STEP);
		}else if(typeid(*(*ite)) == typeid(CFoePlaneBig)){//��ɻ�
			(*ite)->MoveFoePlane(FOEBIG_MOVE_STEP);
		}
		//�ж��Ƿ����
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
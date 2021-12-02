#include"GunnerBox.h"
#include"../GameConfig/GameConfig.h"


CGunnerBox::CGunnerBox(){
	m_lstGunner.clear();
}
CGunnerBox::~CGunnerBox(){
	list<CGunner*>::iterator ite = m_lstGunner.begin();
	while(ite != m_lstGunner.end()){
		delete (*ite);
		(*ite) = NULL;
		ite++;
	}
	m_lstGunner.clear();
}

void CGunnerBox::ShowAllGUnner(HDC hdc, HDC compHdc){
	list<CGunner*>::iterator ite = m_lstGunner.begin();
	while(ite != m_lstGunner.end()){
		(*ite)->ShowGunner(hdc,compHdc);

		ite++;
	}
}
void CGunnerBox::MoveAllGunner(int step){
	list<CGunner*>::iterator ite = m_lstGunner.begin();
	while(ite != m_lstGunner.end()){
		(*ite)->MoverGunder(step);
		if((*ite)->m_ny <= -MAPSIZE_GUNNER_HEIGH){
			ite = m_lstGunner.erase(ite);
			continue;
		}
		ite++;
	}
}
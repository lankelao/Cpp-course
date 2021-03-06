//====================================头文件==================================================
//----------------------------配置文件-----------------------------
#define ANIMAL_KIND_CAT 1//种类
#define ANIMAL_KIND_DOG 2
#define ANIMAL_KIND_SNA 3

#define ANIMAL_CAT_COST 4//单价
#define ANIMAL_DOG_COST 6
#define ANIMAL_SNA_COST 10

#define PEOPLE_MONEY 100

#define CMD_BUY_ANIMAL_DOG   "buy dog"
#define CMD_BUY_ANIMAL_CAT   "buy cat"
#define CMD_BUY_ANIMAL_SNA   "buy snake"

#define CMD_PROGRAM_QUIT        "quit"

#define CMD_LOOK_ANIMAL		"look"
#define CMD_KILL_ANIMAL		"kill"
#define CMD_DESTROY_CAGE	"destroy"
#define CMD_PLAY_ANIMAL		"play"
#define CMD_SHOW_PEOPLE		"show"

#define CMD_HELP		"help"
//----------------------------猫-----------------------------
#pragma once
#include "animal.h"
class CCat :
	public CAnimal
{
public:
	CCat(void);
	~CCat(void);
public:
	virtual void PlayAnimal();
};
//-----------------------------狗----------------------------
#pragma once
#include "animal.h"
class CDog :
	public CAnimal
{
public:
	CDog(void);
	~CDog(void);
public:
	virtual void PlayAnimal();
};
//----------------------------蛇-----------------------------
#pragma once
#include "animal.h"
class CSnake :
	public CAnimal
{
public:
	CSnake(void);
	~CSnake(void);
public:
	virtual void PlayAnimal();
};
//-----------------------------动物----------------------------
#pragma once
#include<string>
using namespace std;
class CAnimal
{
public:
	CAnimal(void);
	virtual ~CAnimal(void);
public:
	int m_nAge;
	string m_strColor;
	string m_strName;
public:
	virtual void PlayAnimal()=0;
	void InitAnimal(string& name, string& color, int age);
	void ShowAnimal();
};
//------------------------------笼子---------------------------
#pragma once
#include"Animal.h"
class CCage
{
public:
	CCage(void);
	~CCage(void);
public:
	CAnimal *m_pAni;
	int m_nId;
public:
	void InitCage(int id);
};
//------------------------------房子---------------------------
#pragma once
#include<list>
using namespace std;
#include"Cage.h"

class CHouse
{
public:
	CHouse(void);
	~CHouse(void);
public:
	list<CCage*>m_lstCage;
};
//------------------------------人---------------------------
#pragma once
#include"House.h"

class CPeople
{
public:
	CPeople(void);
	~CPeople(void);
public:
	int m_nMoney;
	string m_strName;
public:
	void InitPeople(string& name, int money);
	void ShowPeople();
	bool BuyAnimal(CAnimal *pAni, int animalKind);
	CCage*CreateCage();
	void PushAnimal(CCage* pCage, CAnimal* pAni);
	void PushCage(CHouse* pHouse, CCage *pCage);
	void LookAnimal(CHouse* pHouse, int id);
	void Destroy(CHouse* pHouse, int id);
	void KillAnimal(CHouse* pHouse, int id);
	void PlayWithAnimal(CHouse* pHouse, int id);
};
//====================================源文件==================================================
//----------------------------猫-----------------------------
#include "Cat.h"
#include<iostream>
using namespace std;

CCat::CCat(void)
{
}


CCat::~CCat(void)
{
}


void CCat::PlayAnimal(){
	cout<<"喵喵喵~"<<endl;
}
//----------------------------狗-----------------------------
#include "Dog.h"
#include<iostream>
using namespace std;

CDog::CDog(void)
{
}


CDog::~CDog(void)
{
}


void CDog::PlayAnimal(){
	cout<<"汪汪汪~"<<endl;
}
//----------------------------蛇-----------------------------
#include "Snake.h"
#include<iostream>
using namespace std;

CSnake::CSnake(void)
{
}


CSnake::~CSnake(void)
{
}


void CSnake::PlayAnimal(){
	cout<<"˻˻˻~"<<endl;
}
//----------------------------动物-----------------------------
#include "Animal.h"
#include<iostream>
using namespace std;

CAnimal::CAnimal(void)
{
	m_strName = "";
	m_strColor = "";
	m_nAge = 0;
}


CAnimal::~CAnimal(void)
{
	m_strName = "";
	m_strColor = "";
	m_nAge = 0;
}


void CAnimal::InitAnimal(string& name, string& color, int age){
	m_strName = name;
	m_strColor = color;
	m_nAge = age;
}
void CAnimal::ShowAnimal(){
	cout<<"Animal info:name="<<m_strName<<",color="<<m_strColor<<",age="<<m_nAge<<endl;
}
//----------------------------笼子-----------------------------
#include "Cage.h"


CCage::CCage(void)
{
	m_pAni = NULL;
	m_nId = 0;
}


CCage::~CCage(void)
{
}

void CCage::InitCage(int id){
	m_nId = id;
}
//----------------------------房子-----------------------------
#include "House.h"


CHouse::CHouse(void)
{
	m_lstCage.clear();
}


CHouse::~CHouse(void)
{
	list<CCage*>::iterator ite = m_lstCage.begin();

	while(ite != m_lstCage.end())
	{
		//先删除动物
		if((*ite)->m_pAni){
			delete(*ite)->m_pAni;
			(*ite)->m_pAni = NULL;
		}
		//再删除笼子
		delete(*ite);
		(*ite) = NULL;
		ite = m_lstCage.erase(ite); //等于ite++;
	}
	m_lstCage.clear();
}
//----------------------------人-----------------------------
#include "People.h"
#include<iostream>
using namespace std;
#include"Def_config.h"

CPeople::CPeople(void)
{
	m_nMoney = 0;
	m_strName = "";
}


CPeople::~CPeople(void)
{
	m_nMoney = 0;
	m_strName = "";
}


void CPeople::InitPeople(string& name, int money){
	m_nMoney = money;
	m_strName = name;
}
void CPeople::ShowPeople(){
	cout<<"People info:name="<<m_strName<<",money"<<m_nMoney<<endl;
}

//--------------------------------------宏替换----------------------------------------
#define BUY_ANIMAL(ANIMAL_COST)\
	if(m_nMoney-ANIMAL_COST<0){\
		cout<<"你没钱了"<<endl;\
		return false;\
	}\
	m_nMoney-=ANIMAL_COST;
#define RANGE_BEGIN()\
		list<CCage*>::iterator ite = pHouse->m_lstCage.begin();\
		while(ite != pHouse->m_lstCage.end()){
#define RANGE_END()\
			ite++;\
		}
#define HOUSE_NULL()\
	if(pHouse == NULL){\
		cout<<"没有房子"<<endl;\
		return;\
	}
//-----------------------------------------------------------------------------------

bool CPeople::BuyAnimal(CAnimal *pAni, int animalKind){
	if(pAni == NULL){
		cout<<"动物为空，你被骗了"<<endl;
		return false;
	}
	switch (animalKind)
	{
	case ANIMAL_KIND_CAT:
		{
			//if(m_nMoney-ANIMAL_CAT_COST<0){
			//	cout<<"你没钱了"<<endl;
			//	return false;
			//}
			//m_nMoney-=ANIMAL_CAT_COST;
			BUY_ANIMAL(ANIMAL_CAT_COST)
		}
		break;
	case ANIMAL_KIND_DOG:
		{
			//if(m_nMoney-ANIMAL_DOG_COST<0){
			//	cout<<"你没钱了"<<endl;
			//	return false;
			//}
			//m_nMoney-=ANIMAL_DOG_COST;
			BUY_ANIMAL(ANIMAL_DOG_COST)
		}
		break;
	case ANIMAL_KIND_SNA:
		{
			//if(m_nMoney-ANIMAL_SNA_COST<0){
			//	cout<<"你没钱了"<<endl;
			//	return false;
			//}
			//m_nMoney-=ANIMAL_SNA_COST;
			BUY_ANIMAL(ANIMAL_SNA_COST)
		}
		break;
	}
	return true;
}
CCage*CPeople::CreateCage(){
	CCage* pCage = new CCage;
	int id = 0;
	do{
		cout<<"请输入笼子编号（编号大于0）"<<endl;
		cin>>id;
	}while(id<=0);
	pCage->InitCage(id);

	return pCage;
}
void CPeople::PushAnimal(CCage* pCage, CAnimal* pAni){
	if(pCage == NULL){
		cout<<"没有笼子"<<endl;
		return;
	}
	if(pAni == NULL){
		cout<<"没有动物"<<endl;
		return;
	}
	pCage->m_pAni = pAni;
	cout<<"动物成功装入笼子"<<endl;

}
void CPeople::PushCage(CHouse* pHouse, CCage *pCage){
	//if(pHouse == NULL){
	//	cout<<"没有房子"<<endl;
	//	return;
	//}
	HOUSE_NULL()
	if(pCage == NULL){
		cout<<"没有笼子"<<endl;
	}
	pHouse->m_lstCage.push_back(pCage);
	cout<<"笼子成功装入到房子里"<<endl;
}
void CPeople::LookAnimal(CHouse* pHouse, int id){
	//if(pHouse == NULL){
	//	cout<<"没有房子"<<endl;
	//	return;
	//}
	HOUSE_NULL()
	if(id == 0){//代表查看所有笼子里的动物
		//list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
		//while(ite != pHouse->m_lstCage.end()){
		RANGE_BEGIN()
			//先判断有没有笼子
			if((*ite)){
				cout<<"笼子编号：id ="<<(*ite)->m_nId<<" :";
				//判断笼子里面是否有动物
				if((*ite)->m_pAni){
					(*ite)->m_pAni->ShowAnimal();
				}else{//没有动物,提示为空
					cout<<"没有动物"<<endl;
				}
			}
		RANGE_END()
		//	ite++;
		//}
	}else{//遍历匹配笼子id
		//list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
		//while(ite != pHouse->m_lstCage.end()){
		RANGE_BEGIN()
			if((*ite)){
				if((*ite)->m_nId == id){//匹配到
					cout<<"笼子编号：id ="<<(*ite)->m_nId<<" :";
					//判断笼子里面是否有动物
					if((*ite)->m_pAni){
						(*ite)->m_pAni->ShowAnimal();
					}else{//没有动物,提示为空
						cout<<"没有动物"<<endl;
					}
					return;
				}
			}
		RANGE_END()
		//	ite++;
		//}
	}
}

void CPeople::KillAnimal(CHouse* pHouse, int id){
	//if(pHouse == NULL){
	//	cout<<"没有房子"<<endl;
	//	return;
	//}
	HOUSE_NULL()
	//list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
	//	while(ite != pHouse->m_lstCage.end()){
		RANGE_BEGIN()
			if((*ite) && (*ite)->m_nId == id){//匹配到笼子
				if((*ite)->m_pAni){
					delete (*ite)->m_pAni;
					(*ite)->m_pAni = NULL;
				}
				cout<<"成功杀死动物"<<endl;
				return;
			}
		RANGE_END()
		//	ite++;
		//}
		//没有匹配到笼子
		cout<<"没有找到笼子，杀死动物失败"<<endl;
}
//销毁笼子
void CPeople::Destroy(CHouse* pHouse, int id){
	//if(pHouse == NULL){
	//	cout<<"没有房子"<<endl;
	//	return;
	//}
	HOUSE_NULL()
	//list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
	//	while(ite != pHouse->m_lstCage.end()){
		RANGE_BEGIN()
			if((*ite) && (*ite)->m_nId == id){
				//先去删除动物
				if((*ite)->m_pAni){
					delete (*ite)->m_pAni;
					(*ite)->m_pAni = NULL;
				}
				//再销毁笼子
				delete(*ite);
				(*ite) = NULL;
				//删除链表节点
				pHouse->m_lstCage.erase(ite);
				return;
			}
		RANGE_END()
		//	ite++;
		//}
		cout<<"没有找到对应的笼子"<<endl;
}
void CPeople::PlayWithAnimal(CHouse* pHouse, int id){
	//if(pHouse == NULL){
	//	cout<<"没有房子"<<endl;
	//	return;
	//}
	HOUSE_NULL()
	//list<CCage*>::iterator ite = pHouse->m_lstCage.begin();
	//	while(ite != pHouse->m_lstCage.end()){
		RANGE_BEGIN()
			if((*ite) && (*ite)->m_nId == id){//匹配到笼子
				if((*ite)->m_pAni){
					cout<<"name = "<<m_strName<<"正在玩耍"<<" :";
					(*ite)->m_pAni->PlayAnimal();
				}
				return;
			}
		RANGE_END()
		//	ite++;
		//}
		cout<<"没有找到对应的笼子"<<endl;
}
//--------------------------------------主函数----------------------------------------
#include<iostream>
#include<sstream>
using namespace std;

#include"People.h"
#include"House.h"
#include"Def_config.h"
#include"Animal.h"
#include"Dog.h"
#include"Cat.h"
#include"Snake.h"

#define DEF_BUY_ANIMAL(ANI_CLASS,ANI_KIND)\
		pAni = new ANI_CLASS;\
		GetAnimalAttr(name,color,age);\
		pAni->InitAnimal(name,color,age);\
		pPeo->BuyAnimal(pAni,ANI_KIND);

#define DEF_INPUT_ID(COUT_INFO)\
		int id = 0;\
		cout<<COUT_INFO<<endl;\
		cin>>id;

void GetAnimalAttr(string &name,string &color,int &age){
	cout<<"请输入动物的名字、颜色、年龄"<<endl;
	string aniAttr;//动物属性
	getline(cin,aniAttr);
	stringstream ss(aniAttr);//字符流
	string s;
	int i = 0;
	while(ss>>s){
		switch (i){
		case 0:
			{
				name = s;
			}
			break;
		case 1:
			{
				color = s;
			}
			break;
		case 2:
			{
				age = atoi(s.c_str());
			}
			break;
		}
		i++;
	} 
}

void ShowHelp(){
	cout<<CMD_BUY_ANIMAL_DOG<<": 买狗"<<endl;
	cout<<CMD_BUY_ANIMAL_CAT<<": 买猫"<<endl;
	cout<<CMD_BUY_ANIMAL_SNA<<": 买蛇"<<endl;
	cout<<CMD_PROGRAM_QUIT<<": 退出"<<endl;
	cout<<CMD_LOOK_ANIMAL<<": 查看动物"<<endl;
	cout<<CMD_KILL_ANIMAL<<": 杀死动物"<<endl;
	cout<<CMD_DESTROY_CAGE<<": 销毁笼子"<<endl;
	cout<<CMD_PLAY_ANIMAL<<": 和动物玩耍"<<endl;
	cout<<CMD_SHOW_PEOPLE<<": 显示人物信息"<<endl;
}

int main(){
	CPeople *pPeo = new CPeople;
	pPeo->InitPeople(string("李明"),PEOPLE_MONEY);

	CHouse *pHouse = new CHouse;

	string cmd;
	ShowHelp();
	while(1){
		//cin >>cmd;
		cin.sync();
		getline(cin,cmd);//默认\n结束

		if(CMD_PROGRAM_QUIT == cmd){
			break;
		}

		if(cmd == CMD_HELP){
			ShowHelp();
		}

		{//在这加括号是让变量在这里用完就销毁，不干扰外面的东西
			CAnimal *pAni = NULL;
			string name;
			string color;
			int age;
			if(CMD_BUY_ANIMAL_DOG == cmd){
				cout<<"买狗"<<endl;
				//pAni  = new CDog;
				////CAnimal *pAni = new CDog;
				////string name;
				////string color;
				////int age;
				//GetAnimalAttr(name,color,age);
				//pAni->InitAnimal(name,color,age);
				//pPeo->BuyAnimal(pAni,ANIMAL_KIND_DOG);
				DEF_BUY_ANIMAL(CDog,ANIMAL_KIND_DOG)
			}else if(CMD_BUY_ANIMAL_CAT == cmd){
				cout<<"买猫"<<endl;
				//pAni = new CCat;
				//GetAnimalAttr(name,color,age);
				//pAni->InitAnimal(name,color,age);
				//pPeo->BuyAnimal(pAni,ANIMAL_KIND_CAT);
				DEF_BUY_ANIMAL(CCat,ANIMAL_KIND_CAT)
			}else if(CMD_BUY_ANIMAL_SNA == cmd){
				cout<<"买蛇"<<endl;
				//pAni = new CSnake;
				//GetAnimalAttr(name,color,age);
				//pAni->InitAnimal(name,color,age);
				//pPeo->BuyAnimal(pAni,ANIMAL_KIND_SNA);
				DEF_BUY_ANIMAL(CSnake,ANIMAL_KIND_SNA)
			}

			if(pAni){
				//创建笼子
				CCage* pCage = pPeo->CreateCage();
				//装动物
				pPeo->PushAnimal(pCage,pAni);
				//放到房子里
				pPeo->PushCage(pHouse,pCage);
			}
		}
//----------------------查看动物----------------------------------------------
		if(cmd == CMD_LOOK_ANIMAL){
			//int id = 0;
			//cout<<"请输入查看笼子的ID(id==0代表查看所有动物)"<<endl;
			//cin>>id;
			DEF_INPUT_ID("请输入查看笼子的ID(id==0代表查看所有动物)")
			pPeo->LookAnimal(pHouse,id);
		}
		if(cmd == CMD_KILL_ANIMAL){
			//int id = 0;
			//cout<<"请输入要杀死动物笼子的ID"<<endl;
			//cin>>id;
			DEF_INPUT_ID("请输入要杀死动物笼子的ID")
			pPeo->KillAnimal(pHouse,id);
		}
		if(cmd == CMD_DESTROY_CAGE){
			//int id = 0;
			//cout<<"请输入要销毁笼子的ID"<<endl;
			//cin>>id;
			DEF_INPUT_ID("请输入要销毁笼子的ID")
			pPeo->Destroy(pHouse,id);
		}
		if(cmd == CMD_PLAY_ANIMAL){
			//int id = 0;
			//cout<<"请输入和动物玩耍笼子的ID"<<endl;
			//cin>>id;
			DEF_INPUT_ID("请输入和动物玩耍笼子的ID")
			pPeo->PlayWithAnimal(pHouse,id);
		}
		if(cmd == CMD_SHOW_PEOPLE){
			pPeo->ShowPeople();
		}
	}
	//回收人、屋子的空间
	delete pPeo;
	pPeo = NULL;

	delete pHouse;//删除房子的时候，调用析构，笼子动物一并删除
	pHouse = NULL;

	return 0;
}

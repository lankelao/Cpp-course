#include<iostream>
using namespace std;

class CHand{
public:
	void Move(){
		cout<<"手 劈里啪啦~~"<<endl;
	}
};

class CComputer{
public:
	void Complie(){//编码功能
		cout<<"正在编译、生成代码..."<<endl;
	}
};

class CFriend{
public:
	void play(){
		cout<<"大兄弟上号，朋友正在玩游戏..."<<endl;
	}
};

class CPeople{
public:
	CHand m_hand;//定义一个手的对象
	CFriend *m_pFri;//关联的时候有个朋友的指针，需要构造来初始化
	CPeople(){
		m_pFri = NULL;
	}
	~CPeople(){//在这不用delete m_pFri,因为人和朋友没有生命周期约束关系

	}
public:
	void Clap()
	{
		m_hand.Move();
		cout<<"发出阵阵掌声~~"<<endl;
	}
	void Code(CComputer *comp){//人要用电脑 要通过参数
		if(comp){
			m_hand.Move();
			cout<<"劈里啪啦，敲代码"<<endl;

			comp->Complie();//编译
			cout<<"生成可执行程序"<<endl;
		}
	}
	void SetFriend(CFriend *pFri){//交朋友，通过一个函数，写了一个方法设置值
		m_pFri = pFri;
	}
	void PlayWangZhe(){
		if(m_pFri){
			m_pFri->play();
		}
		cout<<"我正在打王者..."<<endl;
	}
};

class CFamily{
public:
	CPeople *m_pPeo[10];//有一个人的数组
public:
	CFamily(){
		for(int i=0;i<10;i++){
			m_pPeo[i] = NULL;//初始值为NULL
		}
	}
	~CFamily(){//聚合有生命周期约束关系，家庭不在的时候，人也会销毁
		for(int i=0;i<10;i++){
			if(m_pPeo){
				delete m_pPeo[i];
				m_pPeo[i] = NULL;
			}
		}
	}
public:
	void PushPeople(CPeople *pPeo){//家庭里添加人
		for(int i=0;i<10;i++){
			if(m_pPeo[i] == NULL){//哪个位置是NULL，添加人
				m_pPeo[i] = pPeo;
				return;//一定return
			}
		}
	}
	void AllPeopleCode(CComputer *computer){
		for(int i=0;i<10;i++){
			if(m_pPeo[i]){
				m_pPeo[i]->Code(computer);
			}
		}
	}
};

int main()
{
//--------------------------组合（复合）------------------------
	CPeople people;//定义一个自己
	people.Clap();//调用鼓掌功能

//--------------------------依赖-------------------------------
	CComputer *pComp = new CComputer;
	people.Code(pComp);

	delete pComp;//电脑没了，people.Code(pComp)也就不输出了
	pComp = NULL;
	people.Code(pComp);
//--------------------------关联-------------------------------
	CFriend *pFri = new CFriend;//定义一个朋友
	people.SetFriend(pFri);//先交一个朋友people.m_pFri = pFri
	people.PlayWangZhe();

	delete pFri;
	pFri = NULL;
	people.m_pFri = NULL;//朋友没了，朋友指针也赋空
	people.PlayWangZhe();//朋友没了，自己依然可以玩游戏
//--------------------------聚合-------------------------------
	CFamily family;
	CPeople *pPeo1 = new CPeople;
	CPeople *pPeo2 = new CPeople;
	CPeople *pPeo3 = new CPeople;
	CPeople *pPeo4 = new CPeople;

	family.PushPeople(pPeo1);
	family.PushPeople(pPeo2);
	family.PushPeople(pPeo3);
	family.PushPeople(pPeo4);

	CComputer *pComp1 = new CComputer;
	family.AllPeopleCode(pComp1);

	system("pause");
	return 0;
}
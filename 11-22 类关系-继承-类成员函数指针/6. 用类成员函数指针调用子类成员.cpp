#include<iostream>
using namespace std;

class People{
public:
	void play(){
		cout<<"playplay"<<endl;
	}
};

class CYellowPeople:public People{
public:
	void play(){
		cout<<"playplay"<<endl;
	}
};

typedef void(People::*P_FUN)();
//ȥָ��ͬ�����࣬���ò�ͬ����ĳ�Ա
void GetPlay(People *peo,P_FUN p_fun){
	(peo->*p_fun)();
}

int main()
{
	//Ҫ������಻��ָ����������
	
	P_FUN p_fun = (P_FUN)&CYellowPeople::play;
	People* pPeo = new CYellowPeople;

	(pPeo->*p_fun)();

	GetPlay(pPeo,(P_FUN)&CYellowPeople::play);//����ָ�룬���Ա����ָ��


	system("pause");
	return 0;
}
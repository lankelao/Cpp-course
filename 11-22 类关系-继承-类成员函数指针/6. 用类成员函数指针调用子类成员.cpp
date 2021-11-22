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
//去指向不同的子类，调用不同子类的成员
void GetPlay(People *peo,P_FUN p_fun){
	(peo->*p_fun)();
}

int main()
{
	//要解决父类不能指向子类问题
	
	P_FUN p_fun = (P_FUN)&CYellowPeople::play;
	People* pPeo = new CYellowPeople;

	(pPeo->*p_fun)();

	GetPlay(pPeo,(P_FUN)&CYellowPeople::play);//父类指针，类成员函数指针


	system("pause");
	return 0;
}
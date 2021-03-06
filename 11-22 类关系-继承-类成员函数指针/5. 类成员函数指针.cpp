#include<iostream>
using namespace std;

//==================================================
//函数指针好处：将实现同一功能的不同模块统一表示起来，使代码结构更加清晰，后期更容易维护，
//			  提高了代码的复用性、拓展性，便于分层设计，利于系统抽象，降低代码耦合度
void play(){
	cout<<"play"<<endl;
}
void (*p_fun)() = &play;  //函数指针，小写是变量
typedef void (*P_FUN1)();		//typedef优化,大写说明它是一个类型，可以定义一个变量

void GetPlay(P_FUN1 p_fun/*相当于接口*/){
	(*p_fun)();
}
//==================================================

//隐藏：父类和子类中有同名的函数
class CFather{
public:
	void show(int a,int b,int c){//不是函数重载的关系，是隐藏
		cout<<"show(int a,int b,int c)"<<endl;
	}
};

class CSon:public CFather
{
public:
	void show(int a){
		cout<<"show(int a)"<<endl;
	}
	void show(int a,int b){
		cout<<"show(int a,int b)"<<endl;
	}
};

//::*定义类成员函数指针,::*是一个整体操作符，不可分开，它是定义在类外可以指向类成员函数的一个特殊的指针
typedef void (CSon::*P_FUN2)(int a,int b);
int main()
{
//==================================================
	play();//=::Play()可以直接调用，也可以用函数指针
	(*p_fun)();//函数指针，间接引用
	P_FUN1 p_fun1 = &play;
	(*p_fun1)();
	GetPlay(&play);
//==================================================
	CSon son;
	son.show(1);
	son.show(1,2);
	//son.show(1,2,3);	//❌
	son.CFather::show(1,2,3);

	//类成员函数指针
	P_FUN2 p_fun2 = &CSon::show;//可以指向类成员函数
	//.* :用对象去调用类成员函数指针，是一个整体的操作符，不可分开
	CSon son2;
	(son2.*p_fun2)(3,4);
	//->*: 用指针对象去调用类成员函数指针，是一个整体的操作符，不可分开
	CSon *pSon = new CSon;
	(pSon->*p_fun2)(5,6);

	system("pause");
	return 0;
}
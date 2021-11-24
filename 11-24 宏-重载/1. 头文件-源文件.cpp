//头文件：变量、函数、类型的声明，类的定义，宏
//源文件：函数的实现，变量的实现

//-------------------声明-----------------------------
//区分声明和定义：在内存中有没有申请空间
void show(int a);	//函数声明

extern int c;	//声明
//int a;	//变量的定义，不是声明
//extern int c = 10;	//也是定义
//int b = 10;   //定义并且初始化

class CTest{
public:
	int m_a;
	const int m_b;//只能在参数列表中初始化
	static int m_c;//在类外初始化
	CTest();
	~CTest();	
public:
	void show();		//类成员函数的声明
	static void play();  //静态成员函数
	void code()const;		//常函数声明
	virtual void run();		//虚函数
	//virtual void drink() = 0;	//纯虚函数，不需要在源文件中定义
};
//-------------------声明-----------------------------
#include<iostream>
#include"标头.h"
using namespace std;

int CTest::m_c = 40;//需要放在源文件中初始化

void show(int a)
{
	cout<<"show\t"<<a<<endl;
}
int c = 30;

CTest::CTest():m_b(20){  //函数实现需要加类名作用域
	m_a = 10;
}
CTest::~CTest(){

}

void CTest::show(){
	cout<<m_a<<endl;
	cout<<m_b<<endl;
	cout<<m_c<<endl;
}
void CTest::play()//静态成员函数的实现需要去掉static
{
	cout<<"static play"<<endl;
}
void CTest::code()const{//常函数在源文件中定义，需要保留关键字，this指针前加const
	cout<<"const"<<endl;
}
void  CTest::run()//虚函数的实现需要去掉Virtual
{
	cout<<"Virtual run"<<endl;

}
//-------------------调用-----------------------------
#include<Windows.h>
#include"标头.h"
#include<iostream>

int main()
{
	show(2);
	std::cout<<c<<std::endl;

	CTest tst;
	tst.show();
	tst.play();
	CTest::play();
	tst.run();
	tst.code();
	system("pause");
	return 0;
}
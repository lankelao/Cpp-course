#include<iostream>
using namespace std;
/*
静态成员属性：不属于对象，属于类的，编译期就存在了，初始化需要在类外进行初始化
所有对象共享这个静态成员变量，
*/
class CTest{
public:
	static int m_a;
	int m_b;
	CTest(){
		cout<<m_a<<endl;
		//m_a = 20;  //赋值
	}
	void Show(){
		cout<<m_a<<endl;  //this->m_a
		cout<<m_b<<endl;  //this->m_b
		this;
		CTest::play();
	}
	//-------------------------------
	// 编译期就存在，属于类，只有一份，可以用对象去调用，也可以  类名::   直接去使用
	//静态成员函数没有隐藏this 指针,和普通成员函数的最大区别
	static void play(){
		cout<<"void play()"<<endl;
		//cout<<m_b<<endl;
		cout<<m_a<<endl;
		//this;
	
	}
};

// 类型 类名::变量名 = 初始化值

int CTest::m_a = 10;


int main(){
	//CTest tst;
	//cout<< sizeof(CTest)<<endl;  //1

	//cout<< CTest::m_a<<endl;  //使用方法
	//cout<<tst.m_a<<endl; //使用方法


	/*CTest tst1;
	cout<< tst1.m_a<<endl;

	tst1.m_a = 12;

	CTest tst2;
	cout<<tst2.m_a<<endl;*/


	CTest tst;
	tst.play();

	CTest::play();



	system("pause");
	return 0;
}
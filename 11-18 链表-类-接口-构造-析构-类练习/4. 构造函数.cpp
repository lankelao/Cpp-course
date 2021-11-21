#include<iostream>
using namespace std;

//构造函数：空类里编译器会提供一个默认的无参的构造函数，函数体代码为空
//函数名：是当前类名,没有返回值，参数可以有也可以没有
//构造函数：用来初始化类成员变量(成员属性）
//定义对象的时候,自动调用
//构造函数可以有多个，他们之间是函数重载的关系，定义对象最终只执行某一个构造函数
class CTest{
public:
	int m_nAge;
public:
	CTest()
	{
		m_nAge = 10;
	}
	CTest(int age){
		m_nAge = age;
	}
};

int main()
{
	CTest tst;//调用无参的构造函数
	cout<< tst.m_nAge <<endl;

	CTest tst1(11);//调用有参的构造函数
	cout<< tst1.m_nAge <<endl;

	system("pause");  
}

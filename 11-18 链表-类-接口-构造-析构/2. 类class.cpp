#include<iostream>
#include<string>
using namespace std;

//C数据和算法彼此关联性不强，互不关联
//C++将完成某一功能的数据算法封装起来，形成一个类
//类：它是数据和算法的集合,它是一个抽象的概念
//对象：定义一个类的实例(变量)，它是具体的概念

class CPeople{//关键词class,类名开头一般用C
	//变量叫成员变量，函数叫成员函数,成员变量定义规则一般m_n(类型)
private:
	int m_nAge;
protected:
	bool m_bSex;
public:
	string m_strName;
public:
	void show(){  //成员函数可以直接用成员变量
		cout<<m_nAge<<endl;
		cout<<m_bSex<<endl;
		cout<<m_strName<<endl;
	}

};

int main()
{
	CPeople people;	//定义一个对象
//访问修饰符：
//public:公共的  类内类外都能用
//protected:保护的  类内可以，子类中也可以
//private:私有的    只能类内使用，不写默认私有的，直到遇到下一个修饰符

	people.m_nAge = 10;
	people.m_bSex = 0;
	people.m_strName = "小明";

	people.show();//必须用对象people.

	CPeople* pPeo = new CPeople;
	pPeo->m_strName = "小虎";	//用->先定义指针
	system("pause");  
}

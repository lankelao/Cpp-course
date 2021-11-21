#include<iostream>
#include<string>
using namespace std;

//构造函数：空类里编译器会提供一个默认的无参的构造函数
class CPeople{
private:
	int m_nAge;
protected:
	bool m_bSex;
public:
	string m_strName;
public:
	void show(){  
		cout<<m_nAge<<endl;
		cout<<m_bSex<<endl;
		cout<<m_strName<<endl;
	}
//对于私有变量，我们可以提供一个接口去设置、获取值
	void SetAge(int age){
		m_nAge = age;
	}
	int GetAge()
	{
		return m_nAge;
	}
};

int main()
{
	CPeople people;	//定义一个对象

	//people.m_nAge = 10;
	//people.m_bSex = 0;
	people.m_strName = "小明";

	people.show();//必须用对象people.

	CPeople* pPeo = new CPeople;
	pPeo->m_strName = "小虎";	//用->先定义指针

	pPeo->SetAge(20);
	cout <<pPeo->GetAge()<<endl;
	system("pause");  
}

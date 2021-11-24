#include<iostream>
using namespace std;
//重载操作符：本质是一个函数，告诉编译器，遇到这个操作符，去调用此函数来执行操作符的功能
//			一般是需要有返回值的，方便继续和后续操作

//类内重载，默认有一个this指针,一般对象在操作符左边，代表用这个对象去调用操作符函数
class CTest{
public:
	int m_a;
	CTest(){
		m_a = 10;
	}
	int operator+(int a){
		return m_a + a;
	}
	int operator=(int a){
		this->m_a = a;
		return m_a;
	}
	int operator+=(int a){
		this->m_a += a;
		return m_a;
	}
	int operator++(){//左++
		return ++this->m_a;
	}
	int operator++(){//右++
		return this->m_a++;
	}
};
int main(){
	CTest tst;
	tst + 10;	//想要的是m_a+10，但两边类型不同，一个对象一个int
	CTest tst1;
	tst1+=20;
	cout<<tst1.m_a<<endl;
	CTest tst2;
	tst2 = tst1+=20;
	cout<<tst2.m_a<<endl;
	CTest tst3;
	tst3 = ++tst1;
	cout<<tst3.m_a<<endl;
	CTest tst4;
	tst4 = tst1++;
	cout<<tst4.m_a<<endl;

	system("pause");
	return 0;
}
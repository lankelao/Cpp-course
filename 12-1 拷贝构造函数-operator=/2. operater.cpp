#include<iostream>
using namespace std;

class CTest{
public:
	int m_a;
	int *m_p;

	CTest(){
		m_a = 10;
		m_p=NULL;
	}
	CTest(int a){
		m_a = a;
		m_p = new int(30);
	}
	int operator=(int a){
		m_a=a;
		return m_a;
	}
	//编译器默认的operator = const CTest & tst const CTest &,
	// 参数中对象给 this对象 成员 依次赋值
	//  当前类的一个对象给另一个对象赋值
	// 也是一个浅拷贝，浅拷贝问题，解决 深拷贝
	/*const CTest & operator =(const CTest & tst){
		this->m_a = tst.m_a;
		return *this;
	}*/
	const CTest & operator =(const CTest & tst){
		this->m_a = tst.m_a;

		if(tst.m_p){
			if(this->m_p){
				*this->m_p = *tst.m_p;
			}else{
				this->m_p = new int(*tst.m_p);
			}
		}else{
			if(this->m_p){
				delete this->m_p;
				this->m_p=NULL;
			}else{
				this->m_p=tst.m_p;
			}	
		}
		return *this;
	}
	~CTest(){
		if(m_p){
			delete m_p;
			m_p=NULL;
		}
	}
};

int main(){

	//CTest tst(20);
	//CTest tst2;
	//tst2 = tst = 10;


	//CTest tst3;
	////CTest tst4;

	////tst4 = tst3 = tst;

	//tst3 = tst;


	CTest tst1;
	CTest tst2;

	//tst2= tst1;
	CTest tst3(20);
	//tst2 = tst3;

	CTest tst4(40);

	//tst4 =tst3;

	tst4 = tst1;

	system("pause");
	return 0;
}
//空类中有哪些默认的函数
/*  4个
1. 默认的无参构造
2. 析构
3. 默认的拷贝构造
4. 默认operator=
*/
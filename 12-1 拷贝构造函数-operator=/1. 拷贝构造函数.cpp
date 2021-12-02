#include<iostream>
using namespace std;

class CTest{
public:
	int m_a;
	int *m_p;

	CTest(){
		m_a = 10;
		m_p =new int(20);
	
	}
	CTest(int a){
		m_a = a;
		m_p = NULL;
	
	}
	// 空类中编译器会提供一个默认的特殊的构造函数：拷贝构造函数
	// 拷贝构造函数 参数 const CTest & tst
	// 用当前类的一个对象给另一个对象初始化
	// 参数中对象给 this对象 成员 依次初始化
	/*CTest(const CTest & tst){
		this->m_a = tst.m_a;
	}*/

	// 默认的拷贝构造函数： 浅拷贝问题
	// 1. 如果类中成员存在指针变量且初始化分配空间，调用拷贝构造函数时，是一个地址拷贝过程，在析构回收空间的时候，
	// 同一个地地址空间 会被delete 多次，导致程序崩溃。
	// 2. 多个对象指针指向同一个空间，其中一个对象修改里面的值，其他对象使用的值是修改后的。

	// 解决浅拷贝问题：深拷贝

	CTest(const CTest & tst){
		this->m_a = tst.m_a;
		//this->m_p = tst.m_p;

		if(tst.m_p){
			this->m_p =new int(*tst.m_p);
		}else{
			this->m_p=NULL;	
		}
	}
	~CTest(){
		if(m_p){
			delete m_p;
			m_p=NULL;
		}	
	}
};

int main(){

	//CTest tst(10);
	//CTest tst1(tst); //
	//cout<<tst1.m_a<<endl;

	//CTest ;
	//CTest tst;

	//CTest tst2(tst);

	//*tst2.m_p  =50;

	//cout<<*tst.m_p<<endl;

	//CTest tst1;
	//CTest tst2(tst1);

	CTest tst3(10);
	CTest tst4(tst3);

	system("pause");
	return 0;
}
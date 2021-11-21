#include<iostream>
using namespace std;

class CTest{
public:
	const int m_a;
	int m_b;
public:
	//初始化参数列表：真正的初始化
	CTest():m_a(10),m_b(30){
		//m_a = 10;   //赋值 ，并不是初始化

		//m_b = 20;  //赋值
	}
	//初始化参数列表的初始化顺序：并不是写在参数列表中的顺序，变量在类中定义顺序
	CTest(int a):m_b(a),m_a(a){
		//m_a = 10;   //赋值 ，并不是初始化

		//m_b = 20;  //赋值
	}
	void play(/*  CTest * const this  */){
	}

	// 常函数：可以使用变量，但不能修改,const 修饰的是 this 指针
	int show(/*  const CTest * const this  */)const{
		cout<<m_a<<endl;
		cout<<m_b<<endl;
		/*m_a=30;
		m_b=30;*/

		return 0;
	}
};

int main(){

	//CTest tst;
	//cout<< tst.m_a<<endl;
	////tst.m_a = 112;

	//cout<<tst.m_b<<endl;

	/*CTest tst(20);
	cout<< tst.m_a<<endl;
	cout<<tst.m_b<<endl;*/

	CTest tst;
	tst.show();

	//const CTest * const pp = &tst;  //指针的安全级别升级的操作，允许
	//pp->m_a=10;

	const CTest tst1;   //常量对象,只能去调用常函数

	tst1.show();

	//tst1.play();

	//CTest * const p2 = &tst1;  // 指针的安全级别降级的操作，不允许

	system("pause");
	return 0;
}
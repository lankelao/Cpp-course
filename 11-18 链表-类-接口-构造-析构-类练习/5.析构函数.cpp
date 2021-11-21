#include<iostream>
using namespace std;

//构造函数：空类里编译器会提供一个默认的无参的构造函数，函数体代码为空
//函数名：是当前类名,没有返回值，参数可以有也可以没有
//构造函数：用来初始化类成员变量(成员属性）
//定义对象的时候,自动调用
//构造函数可以有多个，他们之间是函数重载的关系，定义对象最终只执行某一个构造函数


// 析构函数：释放成员申请空间
// 析构 函数名 ~类名 ，无参数，无返回值，析构函数只有一个
//. 对象的生命周期结束的时候，自动调用
class CTest{
public:
	int m_nAge;
	int m_nSex;
	int *m_p;
public:
	CTest(){
		m_nAge = 10;

		m_p = new int(10);
	}
	CTest(int age){
	
		m_nAge = age;
		m_p =NULL;
	}
	CTest(int age, int sex){
		m_nAge = age;
		m_nSex = sex;
	}

	// 析构
	~CTest(){
		cout<<"~CTest"<<endl;
		if(m_p){
			delete m_p;
			m_p=NULL;
		}
	}

};


int main(){
	//CTest tst;  //调用 无参的构造函数

	//cout<< tst.m_nAge<<endl;

	//CTest tst2(12);

	/*CTest *pTst = new CTest(12,1);

	cout<<pTst->m_nAge<<endl;
	cout<<pTst->m_nSex<<endl;

	delete pTst;*/

	{
		CTest tst;
	}

	system("pause");
	return 0;
}
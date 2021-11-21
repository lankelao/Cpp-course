#include<iostream>
using namespace std;

class CTest{
public:
	int m_a;
public:
	CTest(){
		m_a = 10;
		cout<<"CTest()"<<endl;
	
	}

	CTest(int a){
		m_a = 20;
		cout<<"CTest(int a)"<<endl;
	
	}
	~CTest(){
		cout<<"~CTest()"<<endl;
	
	}

};

// 3. 全局对象， 程序启动自动为对象分配空间，直到 程序结束
//CTest tst2;

// 4. 静态全局对象，生命周期，程序启动自动为对象分配空间，直到 程序结束
//static CTest tst3;
//静态作用范围：文件作用域，全局对象作用范围：整个工程

CTest * ptst=NULL;
void show(){

	static CTest tst;  //声明周期，第一次调用函数的时候创建对象，直到程序结束,在内存中只有一份
	ptst=&tst;
}

// 5 .临时对象
CTest GetTest(){
	CTest tst;
	return tst;
}

int main(){
	//show();
	//cout<< ptst->m_a<<endl;;
	//cout<<"-----------------"<<endl;
	////CTest tst;   //1. 局部对象（栈区）

	////CTest *pTst =new CTest;  //2. new 对象，生命周期 直到 遇到delete
	//show();

	//CTest tst();  //不要这样写，
	//cout<<"----------------"<<endl;
	//CTest (2);   //5.临时对象（匿名对象）:当前这一行，直到遇到;
	//cout<<"----------------"<<endl;


	cout<<"----------------"<<endl;
	GetTest();
	cout<<"----------------"<<endl;


	system("pause");
	return 0;
}
#include<iostream>
using namespace std;
/*
类成员属性：占用对象的内存空间，定义对象时存在,多个对象存在多份

类成员函数：不占用对象的内存空间，占用的是应用程序的内存空间，在编译期就存在，属于类只有一份
*/
class CTest{
public:
	int m_a;
public:
	CTest(int a){
		m_a = a;
	
	}

	//this 指针
	//  CTest *const this;
	// 类中非静态成员函数中有一个默认的隐含的参数 ，this指针  CTest *const this;
	// 用来连接成员属性 和成员方法的桥梁，哪个对象调用了函数this就指向了哪个对象
	void show(/* CTest *const this */){
		cout<<this->m_a<<endl;
	}
	void play(/* CTest *const this */){
		cout<<"play()"<<endl;
		cout<<this->m_a<<endl;
	}
};


int main(){
	//CTest tst;

	//cout<< sizeof(tst)<<endl;
	//cout<< sizeof(CTest) <<endl;  //1: 占位的作用


	//CTest tst;
	//cout<< sizeof(tst)<<endl;
	//cout<< sizeof(CTest) <<endl;  //1: 占位的作用


	//CTest tst1(1);
	//tst1.show();

	//CTest tst2(2);
	//tst2.show();


	CTest *p=NULL;
	//p->m_a = 10;
	p->play();




	system("pause");
	return 0;
}
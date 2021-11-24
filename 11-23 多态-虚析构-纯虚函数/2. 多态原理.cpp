#include<iostream>
using namespace std;
//单个类-------多态原理1
/*虚函数指针：二级指针，只要类中存在虚函数，在定义对象的时候，分配的内存空间就会多出4个字节，它指向了一个数组,
_vfptr		数组的每个元素是一个函数指针，函数指针指向的是虚函数，在构造函数初始化列表中进行初始化，指向了虚
			函数列表，它是属于对象的，定义对象的时候才存在，在定义对象空间的前4个字节

虚函数列表：  它是属于类的，编译期就存在

虚函数调用：	通过虚函数指针->虚函数列表，遍历查找对应的函数指针,->函数指针取调用具体的虚函数
*/
//继承关系下-----多态原理2
//覆盖：子类虚函数重写了父类的虚函数，在虚函数列表中会替换掉父类的虚函数
class CFather{
public:
	CFather(){
		cout<<"fa"<<endl;
	}
public:
	virtual void show(){
		cout<<"CFather::show"<<endl;
	}
	virtual void code(){
		cout<<"CFather::code"<<endl;
	}
};

class CSon:public CFather{
public:
	CSon(){
		cout<<"son"<<endl;
	}
public:
	virtual void play(){
		cout<<"CSon::play"<<endl;
	}
	virtual void show(){
		cout<<"CSon::show"<<endl;
	}
};


int main()
{
//继承不但继承了父类成员还继承了虚函数列表
//new的哪个子类，vfptr最终就指向哪个子类的虚函数列表
	CFather *pFa = new CSon;
	pFa->show();		//"CSon::show"
	//pFa->play();
	CSon *pSon = new CSon;
	pSon->play();
//---------------------------------------------------
	typedef void (*P_FUN)();
	P_FUN p_fun1 = (P_FUN)*(((int*)(*(int*)pFa))+0);
	P_FUN p_fun2 = (P_FUN)*(((int*)(*(int*)pFa))+1);
	P_FUN p_fun3 = (P_FUN)*(((int*)(*(int*)pFa))+2);
	P_FUN p_fun4 = (P_FUN)*(((int*)(*(int*)pFa))+3);

	(*p_fun1)();
	(*p_fun2)();
	(*p_fun3)();
	(*p_fun4)();

	system("pause");
	return 0;
}

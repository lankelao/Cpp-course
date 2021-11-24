#include<iostream>
using namespace std;

//多态：相同的行为方式导致不同的行为结果，
//多态性：同一行语句展现了多种不同的表现形态
//父类的指针可以指向任何继承于该类的子类，且具有子类的行为方式，多种子类具有多种形态
//由父类的指针进行统一管理，父类的指针具有多种形态

//多态产生的条件：
//	1.必须有继承关系存在
//	2.父类的指针指向子类的对象
//	3.子类必须重写父类的虚函数
//	重写：子类中存在和父类一模一样（函数名、参数列表、返回值）的虚函数
class CFather{
public:
	//void Show(){
	//	cout<<"void show"<<endl;
	//}
	virtual void Show(){  //虚函数   重写
		cout<<"virtual void show"<<endl;
	}
};
class CSon1:public CFather
{
public:
	void Show(){
		cout<<"CSon1 show"<<endl;
	}
};
class CSon2:public CFather
{
public:
	void Show(int a){
		cout<<"CSon2 show"<<endl;
	}
};
int main()
{
	CFather *pFa = new CSon1;
	pFa->Show();
	CFather *pFa1 = new CSon2;
	pFa1->Show();

	system("pause");
	return 0;
}
/*虚函数指针：二级指针，只要类中存在虚函数，在定义对象的时候，分配的内存空间就会多出4个字节，它指向了一个数组,
			数组的每个元素是一个函数指针，函数指针指向的是虚函数，在构造函数初始化列表中进行初始化，指向了虚
			函数列表，它是属于对象的，定义对象的时候才存在，在定义对象空间的前4个字节

虚函数列表：  它是属于类的，编译期就存在

虚函数调用：	通过虚函数指针->虚函数列表，遍历查找对应的函数指针,->函数指针取调用具体的虚函数
*/
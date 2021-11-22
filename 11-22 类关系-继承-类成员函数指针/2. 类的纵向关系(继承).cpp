#include<iostream>
using namespace std;

class CFather{//父类（基类）
public:
	int m_father;
	long m_money;
	CFather(){
		m_father = 10;
		m_money = 30;
	};
	void ShowFather(){
		cout<<"ShowFather"<<endl;
	}
	void show(){
		cout<<"CFather::show"<<endl;
	}
	void paly(){
		cout<<"play()"<<endl;
	}
};
//子类名字后面：继承方式+父类类名
//子类可以使用父类的成员：成员属性和成员方法
class CSon:public CFather{//子类（派生类）
public:
	int m_son;
	long m_money;
	CSon(){
		m_son = 20;
		m_money = 40;
	}
	void ShowSon(){
		cout<<"ShowSon"<<endl;
	}
	void show(){
		cout<<"CSon::show"<<endl;
	}
};

int main()
{
	CSon son;
	cout<<son.m_father<<endl;
	cout<<son.m_son<<endl;

	son.ShowFather();
	son.ShowSon();

	cout<<son.m_money<<endl;//重名成员，默认使用子类=son.son::m_money
	cout<<son.CFather::m_money<<endl;//显示父类需要显式指定（类名::）
	

	son.show();//默认子类
	son.CSon::show();
	son.CFather::show();

	son.CSon::paly();

//定义子类的对象，父类成员在内存空间的首位
	cout<<&son<<endl;                   //008FFD50
	cout<<&son.m_father<<endl;			//008FFD50
	cout<<&son.CFather::m_money<<endl;	//008FFD54
	cout<<&son.m_son<<endl;				//008FFD58
	cout<<&son.CSon::m_money<<endl;		//008FFD5C


	system("pause");
	return 0;
}
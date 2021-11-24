#include<iostream>
using namespace std;

//总结多态    多态的缺点：1.效率低2.占用额外空间3.安全性低
class CFather{    
public:
	virtual void play() = 0;		//纯虚函数，子类必须实现这个函数
};

class CSon:public CFather{
public:
	virtual void play(){
		cout<<"play"<<endl;
	}
};

int main()
{
	CSon son;
	son.play();

	//CFather fa;	//抽象类：存在纯虚函数，不允许定义对象
					//接口类：虚函数都是纯虚函数，不允许定义对象			
	system("pause");
	return 0;
}



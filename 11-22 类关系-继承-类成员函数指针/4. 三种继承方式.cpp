#include<iostream>
using namespace std;

/*结构体和类区别：1. 默认访问修饰符  2. 默认的继承方式不同
继承方式-------------public------------------
				父类			子类
				private		不可访问
				protected	protected
				public		pubilc
继承方式-------------protected------------------
				父类			子类
				private		不可访问
				protected	protected
				public		protected
继承方式-------------protected------------------
				父类			子类
				private		不可访问
				protected	private
				public		private
*/
class CFather{
private:
	int m_pri;
protected:
	int m_pro;
public:
	int m_pub;
public:
	CFather(){
		m_pri = 10;
		m_pro = 20;
		m_pub = 30;
	}
};
//----------------------public------------------------
class CSon1:public CFather{
public:
	void show(){
		//cout<<m_pri<<endl;   不可访问
		cout<<m_pro<<endl;
		cout<<m_pub<<endl;
	}
};
class CSonSon1:public CSon1{
	void play(){
		cout<<m_pro<<endl;	//✔
		cout<<m_pub<<endl;	//✔
	}
};
//----------------------protected------------------------
class CSon2:protected CFather{
public:
	void show(){
		//cout<<m_pri<<endl;   不可访问
		cout<<m_pro<<endl;
		cout<<m_pub<<endl;
	}
};
class CSonSon2:public CSon2{
	void play(){
		cout<<m_pro<<endl;	//✔
		cout<<m_pub<<endl;	//✔
	}
};
//----------------------private------------------------
class CSon3:private CFather{
public:
	void show(){
		//cout<<m_pri<<endl;   不可访问
		cout<<m_pro<<endl;	
		cout<<m_pub<<endl;	
	}
};
class CSonSon3:public CSon3{
	void play(){
		cout<<m_pro<<endl;	//❌
		cout<<m_pub<<endl;	//❌
	}
};
int main()
{
//----------------------public------------------------
	CSon1 son1;
	son.m_pro = 40;		//❌
	son1.m_pub = 50;		//✔
//----------------------protected----------------------
	CSon2 son2;
	son2.m_pro = 40;		//❌
	son2.m_pub = 50;		//❌
//----------------------private------------------------
	CSon3 son3;
	son3.m_pro = 40;		//❌
	son3.m_pub = 50;		//❌

	system("pause");
	return 0;
}
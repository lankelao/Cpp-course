#include<iostream>
using namespace std;

//继承：将子类中公共的成员提取出来形成父类，子类可以去使用父类中的公共成员，提高了代码的复用性和拓展性
//允许父类的指针指向子类的对象，反过来不行
class People{
public:
	void play(){
		cout<<"playplay"<<endl;
	}
};

class CYellowPeople:public People{
public:
	//void play(){
	//	cout<<"playplay"<<endl;
	//}
};

class CWhitePeople:public People{
//public:
//	void play(){
//		cout<<"playplay"<<endl;
//	}
};

class CBlackPeople:public People{
public:
	//void play(){
	//	cout<<"playplay"<<endl;
	//}
};


int main()
{
	CYellowPeople p1;
	p1.play();
	CWhitePeople p2;
	p2.play();
	CBlackPeople p3;
	p3.play();


	system("pause");
	return 0;
}
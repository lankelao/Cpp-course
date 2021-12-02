#include<iostream>
using namespace std;
//模板方法：将不变的流程（步骤）和可变的实现（细节）分开，将公共的流程抽离到父类形成模板，
//		  具体的实现利用多态在子类中实现。
class CPeople{
public:
	virtual void EatBehavior(){

	}
	virtual void EatStyle(){

	}
	void eat(){
		cout<< "1.盛一碗饭" <<endl;
		EatBehavior();
		EatStyle();
		cout<< "4.嚼一嚼" <<endl;
		cout<< "5.咽下去" <<endl;
		cout<< "6.完毕" <<endl;
	}
};

class CChina:public CPeople{
public:
	virtual void EatBehavior(){
		cout<< "2.端起来，送到嘴边" <<endl;
	}
public:
	virtual void EatStyle(){
		cout<< "3.用筷子扒拉饭" <<endl;
	}
//public:
//	void eat(){
//		cout<< "1.盛一碗饭" <<endl;
//		EatBehavior();
//		EatStyle();
//		cout<< "4.嚼一嚼" <<endl;
//		cout<< "5.咽下去" <<endl;
//		cout<< "6.完毕" <<endl;
//	}
};
class CAmerican:public CPeople{
public:
	virtual void EatBehavior(){
		cout<< "2.嘴靠上去" <<endl;
	}
public:
	virtual void EatStyle(){
		cout<< "3.用刀叉" <<endl;
	}
//public:
//	void eat(){
//		cout<< "1.盛一碗饭" <<endl;
//		EatBehavior();
//		EatStyle();
//		cout<< "4.嚼一嚼" <<endl;
//		cout<< "5.咽下去" <<endl;
//		cout<< "6.完毕" <<endl;
//	}
};
class CIndian:public CPeople{
public:
	virtual void EatBehavior(){
		cout<< "2.嘴靠上去" <<endl;
	}
public:
	virtual void EatStyle(){
		cout<< "3.用手抓" <<endl;
	}
//public:
//	void eat(){
//		cout<< "1.盛一碗饭" <<endl;
//		EatBehavior();
//		EatStyle();
//		cout<< "4.嚼一嚼" <<endl;
//		cout<< "5.咽下去" <<endl;
//		cout<< "6.完毕" <<endl;
//	}
};

int main(){

	CPeople *pPeo1 = new CChina;
	pPeo1->eat();
	CPeople *pPeo2 = new CAmerican;
	pPeo2->eat();
	CPeople *pPeo3 = new CIndian;
	pPeo3->eat();

	system("pause");
	return 0;
}
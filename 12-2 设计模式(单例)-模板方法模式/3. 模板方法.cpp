#include<iostream>
using namespace std;
//ģ�巽��������������̣����裩�Ϳɱ��ʵ�֣�ϸ�ڣ��ֿ��������������̳��뵽�����γ�ģ�壬
//		  �����ʵ�����ö�̬��������ʵ�֡�
class CPeople{
public:
	virtual void EatBehavior(){

	}
	virtual void EatStyle(){

	}
	void eat(){
		cout<< "1.ʢһ�뷹" <<endl;
		EatBehavior();
		EatStyle();
		cout<< "4.��һ��" <<endl;
		cout<< "5.����ȥ" <<endl;
		cout<< "6.���" <<endl;
	}
};

class CChina:public CPeople{
public:
	virtual void EatBehavior(){
		cout<< "2.���������͵����" <<endl;
	}
public:
	virtual void EatStyle(){
		cout<< "3.�ÿ��Ӱ�����" <<endl;
	}
//public:
//	void eat(){
//		cout<< "1.ʢһ�뷹" <<endl;
//		EatBehavior();
//		EatStyle();
//		cout<< "4.��һ��" <<endl;
//		cout<< "5.����ȥ" <<endl;
//		cout<< "6.���" <<endl;
//	}
};
class CAmerican:public CPeople{
public:
	virtual void EatBehavior(){
		cout<< "2.�쿿��ȥ" <<endl;
	}
public:
	virtual void EatStyle(){
		cout<< "3.�õ���" <<endl;
	}
//public:
//	void eat(){
//		cout<< "1.ʢһ�뷹" <<endl;
//		EatBehavior();
//		EatStyle();
//		cout<< "4.��һ��" <<endl;
//		cout<< "5.����ȥ" <<endl;
//		cout<< "6.���" <<endl;
//	}
};
class CIndian:public CPeople{
public:
	virtual void EatBehavior(){
		cout<< "2.�쿿��ȥ" <<endl;
	}
public:
	virtual void EatStyle(){
		cout<< "3.����ץ" <<endl;
	}
//public:
//	void eat(){
//		cout<< "1.ʢһ�뷹" <<endl;
//		EatBehavior();
//		EatStyle();
//		cout<< "4.��һ��" <<endl;
//		cout<< "5.����ȥ" <<endl;
//		cout<< "6.���" <<endl;
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
#include<iostream>
using namespace std;

class CFather{//���ࣨ���ࣩ
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
//�������ֺ��棺�̳з�ʽ+��������
//�������ʹ�ø���ĳ�Ա����Ա���Ժͳ�Ա����
class CSon:public CFather{//���ࣨ�����ࣩ
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

	cout<<son.m_money<<endl;//������Ա��Ĭ��ʹ������=son.son::m_money
	cout<<son.CFather::m_money<<endl;//��ʾ������Ҫ��ʽָ��������::��
	

	son.show();//Ĭ������
	son.CSon::show();
	son.CFather::show();

	son.CSon::paly();

//��������Ķ��󣬸����Ա���ڴ�ռ����λ
	cout<<&son<<endl;                   //008FFD50
	cout<<&son.m_father<<endl;			//008FFD50
	cout<<&son.CFather::m_money<<endl;	//008FFD54
	cout<<&son.m_son<<endl;				//008FFD58
	cout<<&son.CSon::m_money<<endl;		//008FFD5C


	system("pause");
	return 0;
}
#include<iostream>
#include<string>
using namespace std;

//C���ݺ��㷨�˴˹����Բ�ǿ����������
//C++�����ĳһ���ܵ������㷨��װ�������γ�һ����
//�ࣺ�������ݺ��㷨�ļ���,����һ������ĸ���
//���󣺶���һ�����ʵ��(����)�����Ǿ���ĸ���

class CPeople{//�ؼ���class,������ͷһ����C
	//�����г�Ա�����������г�Ա����,��Ա�����������һ��m_n(����)
private:
	int m_nAge;
protected:
	bool m_bSex;
public:
	string m_strName;
public:
	void show(){  //��Ա��������ֱ���ó�Ա����
		cout<<m_nAge<<endl;
		cout<<m_bSex<<endl;
		cout<<m_strName<<endl;
	}

};

int main()
{
	CPeople people;	//����һ������
//�������η���
//public:������  �������ⶼ����
//protected:������  ���ڿ��ԣ�������Ҳ����
//private:˽�е�    ֻ������ʹ�ã���дĬ��˽�еģ�ֱ��������һ�����η�

	people.m_nAge = 10;
	people.m_bSex = 0;
	people.m_strName = "С��";

	people.show();//�����ö���people.

	CPeople* pPeo = new CPeople;
	pPeo->m_strName = "С��";	//��->�ȶ���ָ��
	system("pause");  
}

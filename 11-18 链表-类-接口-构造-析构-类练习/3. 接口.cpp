#include<iostream>
#include<string>
using namespace std;

//���캯������������������ṩһ��Ĭ�ϵ��޲εĹ��캯��
class CPeople{
private:
	int m_nAge;
protected:
	bool m_bSex;
public:
	string m_strName;
public:
	void show(){  
		cout<<m_nAge<<endl;
		cout<<m_bSex<<endl;
		cout<<m_strName<<endl;
	}
//����˽�б��������ǿ����ṩһ���ӿ�ȥ���á���ȡֵ
	void SetAge(int age){
		m_nAge = age;
	}
	int GetAge()
	{
		return m_nAge;
	}
};

int main()
{
	CPeople people;	//����һ������

	//people.m_nAge = 10;
	//people.m_bSex = 0;
	people.m_strName = "С��";

	people.show();//�����ö���people.

	CPeople* pPeo = new CPeople;
	pPeo->m_strName = "С��";	//��->�ȶ���ָ��

	pPeo->SetAge(20);
	cout <<pPeo->GetAge()<<endl;
	system("pause");  
}

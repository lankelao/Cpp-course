#include<iostream>
using namespace std;

//���캯������������������ṩһ��Ĭ�ϵ��޲εĹ��캯�������������Ϊ��
//���������ǵ�ǰ����,û�з���ֵ������������Ҳ����û��
//���캯����������ʼ�����Ա����(��Ա���ԣ�
//��������ʱ��,�Զ�����
//���캯�������ж��������֮���Ǻ������صĹ�ϵ�������������ִֻ��ĳһ�����캯��
class CTest{
public:
	int m_nAge;
public:
	CTest()
	{
		m_nAge = 10;
	}
	CTest(int age){
		m_nAge = age;
	}
};

int main()
{
	CTest tst;//�����޲εĹ��캯��
	cout<< tst.m_nAge <<endl;

	CTest tst1(11);//�����вεĹ��캯��
	cout<< tst1.m_nAge <<endl;

	system("pause");  
}

#include<iostream>
using namespace std;
//���ز�������������һ�����������߱����������������������ȥ���ô˺�����ִ�в������Ĺ���
//			һ������Ҫ�з���ֵ�ģ���������ͺ�������

//�������أ�Ĭ����һ��thisָ��,һ������ڲ�������ߣ��������������ȥ���ò���������
class CTest{
public:
	int m_a;
	CTest(){
		m_a = 10;
	}
	int operator+(int a){
		return m_a + a;
	}
	int operator=(int a){
		this->m_a = a;
		return m_a;
	}
	int operator+=(int a){
		this->m_a += a;
		return m_a;
	}
	int operator++(){//��++
		return ++this->m_a;
	}
	int operator++(){//��++
		return this->m_a++;
	}
};
int main(){
	CTest tst;
	tst + 10;	//��Ҫ����m_a+10�����������Ͳ�ͬ��һ������һ��int
	CTest tst1;
	tst1+=20;
	cout<<tst1.m_a<<endl;
	CTest tst2;
	tst2 = tst1+=20;
	cout<<tst2.m_a<<endl;
	CTest tst3;
	tst3 = ++tst1;
	cout<<tst3.m_a<<endl;
	CTest tst4;
	tst4 = tst1++;
	cout<<tst4.m_a<<endl;

	system("pause");
	return 0;
}
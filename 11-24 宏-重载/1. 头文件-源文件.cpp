//ͷ�ļ������������������͵���������Ķ��壬��
//Դ�ļ���������ʵ�֣�������ʵ��

//-------------------����-----------------------------
//���������Ͷ��壺���ڴ�����û������ռ�
void show(int a);	//��������

extern int c;	//����
//int a;	//�����Ķ��壬��������
//extern int c = 10;	//Ҳ�Ƕ���
//int b = 10;   //���岢�ҳ�ʼ��

class CTest{
public:
	int m_a;
	const int m_b;//ֻ���ڲ����б��г�ʼ��
	static int m_c;//�������ʼ��
	CTest();
	~CTest();	
public:
	void show();		//���Ա����������
	static void play();  //��̬��Ա����
	void code()const;		//����������
	virtual void run();		//�麯��
	//virtual void drink() = 0;	//���麯��������Ҫ��Դ�ļ��ж���
};
//-------------------����-----------------------------
#include<iostream>
#include"��ͷ.h"
using namespace std;

int CTest::m_c = 40;//��Ҫ����Դ�ļ��г�ʼ��

void show(int a)
{
	cout<<"show\t"<<a<<endl;
}
int c = 30;

CTest::CTest():m_b(20){  //����ʵ����Ҫ������������
	m_a = 10;
}
CTest::~CTest(){

}

void CTest::show(){
	cout<<m_a<<endl;
	cout<<m_b<<endl;
	cout<<m_c<<endl;
}
void CTest::play()//��̬��Ա������ʵ����Ҫȥ��static
{
	cout<<"static play"<<endl;
}
void CTest::code()const{//��������Դ�ļ��ж��壬��Ҫ�����ؼ��֣�thisָ��ǰ��const
	cout<<"const"<<endl;
}
void  CTest::run()//�麯����ʵ����Ҫȥ��Virtual
{
	cout<<"Virtual run"<<endl;

}
//-------------------����-----------------------------
#include<Windows.h>
#include"��ͷ.h"
#include<iostream>

int main()
{
	show(2);
	std::cout<<c<<std::endl;

	CTest tst;
	tst.show();
	tst.play();
	CTest::play();
	tst.run();
	tst.code();
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

class CTest{
public:
	const int m_a;
	int m_b;
public:
	//��ʼ�������б������ĳ�ʼ��
	CTest():m_a(10),m_b(30){
		//m_a = 10;   //��ֵ �������ǳ�ʼ��

		//m_b = 20;  //��ֵ
	}
	//��ʼ�������б�ĳ�ʼ��˳�򣺲�����д�ڲ����б��е�˳�򣬱��������ж���˳��
	CTest(int a):m_b(a),m_a(a){
		//m_a = 10;   //��ֵ �������ǳ�ʼ��

		//m_b = 20;  //��ֵ
	}
	void play(/*  CTest * const this  */){
	}

	// ������������ʹ�ñ������������޸�,const ���ε��� this ָ��
	int show(/*  const CTest * const this  */)const{
		cout<<m_a<<endl;
		cout<<m_b<<endl;
		/*m_a=30;
		m_b=30;*/

		return 0;
	}
};

int main(){

	//CTest tst;
	//cout<< tst.m_a<<endl;
	////tst.m_a = 112;

	//cout<<tst.m_b<<endl;

	/*CTest tst(20);
	cout<< tst.m_a<<endl;
	cout<<tst.m_b<<endl;*/

	CTest tst;
	tst.show();

	//const CTest * const pp = &tst;  //ָ��İ�ȫ���������Ĳ���������
	//pp->m_a=10;

	const CTest tst1;   //��������,ֻ��ȥ���ó�����

	tst1.show();

	//tst1.play();

	//CTest * const p2 = &tst1;  // ָ��İ�ȫ���𽵼��Ĳ�����������

	system("pause");
	return 0;
}
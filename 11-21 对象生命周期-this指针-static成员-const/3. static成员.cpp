#include<iostream>
using namespace std;
/*
��̬��Ա���ԣ������ڶ���������ģ������ھʹ����ˣ���ʼ����Ҫ��������г�ʼ��
���ж����������̬��Ա������
*/
class CTest{
public:
	static int m_a;
	int m_b;
	CTest(){
		cout<<m_a<<endl;
		//m_a = 20;  //��ֵ
	}
	void Show(){
		cout<<m_a<<endl;  //this->m_a
		cout<<m_b<<endl;  //this->m_b
		this;
		CTest::play();
	}
	//-------------------------------
	// �����ھʹ��ڣ������ֻ࣬��һ�ݣ������ö���ȥ���ã�Ҳ����  ����::   ֱ��ȥʹ��
	//��̬��Ա����û������this ָ��,����ͨ��Ա�������������
	static void play(){
		cout<<"void play()"<<endl;
		//cout<<m_b<<endl;
		cout<<m_a<<endl;
		//this;
	
	}
};

// ���� ����::������ = ��ʼ��ֵ

int CTest::m_a = 10;


int main(){
	//CTest tst;
	//cout<< sizeof(CTest)<<endl;  //1

	//cout<< CTest::m_a<<endl;  //ʹ�÷���
	//cout<<tst.m_a<<endl; //ʹ�÷���


	/*CTest tst1;
	cout<< tst1.m_a<<endl;

	tst1.m_a = 12;

	CTest tst2;
	cout<<tst2.m_a<<endl;*/


	CTest tst;
	tst.play();

	CTest::play();



	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

class CTest{
public:
	int m_a;
	int *m_p;

	CTest(){
		m_a = 10;
		m_p=NULL;
	}
	CTest(int a){
		m_a = a;
		m_p = new int(30);
	}
	int operator=(int a){
		m_a=a;
		return m_a;
	}
	//������Ĭ�ϵ�operator = const CTest & tst const CTest &,
	// �����ж���� this���� ��Ա ���θ�ֵ
	//  ��ǰ���һ���������һ������ֵ
	// Ҳ��һ��ǳ������ǳ�������⣬��� ���
	/*const CTest & operator =(const CTest & tst){
		this->m_a = tst.m_a;
		return *this;
	}*/
	const CTest & operator =(const CTest & tst){
		this->m_a = tst.m_a;

		if(tst.m_p){
			if(this->m_p){
				*this->m_p = *tst.m_p;
			}else{
				this->m_p = new int(*tst.m_p);
			}
		}else{
			if(this->m_p){
				delete this->m_p;
				this->m_p=NULL;
			}else{
				this->m_p=tst.m_p;
			}	
		}
		return *this;
	}
	~CTest(){
		if(m_p){
			delete m_p;
			m_p=NULL;
		}
	}
};

int main(){

	//CTest tst(20);
	//CTest tst2;
	//tst2 = tst = 10;


	//CTest tst3;
	////CTest tst4;

	////tst4 = tst3 = tst;

	//tst3 = tst;


	CTest tst1;
	CTest tst2;

	//tst2= tst1;
	CTest tst3(20);
	//tst2 = tst3;

	CTest tst4(40);

	//tst4 =tst3;

	tst4 = tst1;

	system("pause");
	return 0;
}
//����������ЩĬ�ϵĺ���
/*  4��
1. Ĭ�ϵ��޲ι���
2. ����
3. Ĭ�ϵĿ�������
4. Ĭ��operator=
*/
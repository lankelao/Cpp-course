#include<iostream>
using namespace std;

class CTest{
public:
	int m_a;
	int *m_p;

	CTest(){
		m_a = 10;
		m_p =new int(20);
	
	}
	CTest(int a){
		m_a = a;
		m_p = NULL;
	
	}
	// �����б��������ṩһ��Ĭ�ϵ�����Ĺ��캯�����������캯��
	// �������캯�� ���� const CTest & tst
	// �õ�ǰ���һ���������һ�������ʼ��
	// �����ж���� this���� ��Ա ���γ�ʼ��
	/*CTest(const CTest & tst){
		this->m_a = tst.m_a;
	}*/

	// Ĭ�ϵĿ������캯���� ǳ��������
	// 1. ������г�Ա����ָ������ҳ�ʼ������ռ䣬���ÿ������캯��ʱ����һ����ַ�������̣����������տռ��ʱ��
	// ͬһ���ص�ַ�ռ� �ᱻdelete ��Σ����³��������
	// 2. �������ָ��ָ��ͬһ���ռ䣬����һ�������޸������ֵ����������ʹ�õ�ֵ���޸ĺ�ġ�

	// ���ǳ�������⣺���

	CTest(const CTest & tst){
		this->m_a = tst.m_a;
		//this->m_p = tst.m_p;

		if(tst.m_p){
			this->m_p =new int(*tst.m_p);
		}else{
			this->m_p=NULL;	
		}
	}
	~CTest(){
		if(m_p){
			delete m_p;
			m_p=NULL;
		}	
	}
};

int main(){

	//CTest tst(10);
	//CTest tst1(tst); //
	//cout<<tst1.m_a<<endl;

	//CTest ;
	//CTest tst;

	//CTest tst2(tst);

	//*tst2.m_p  =50;

	//cout<<*tst.m_p<<endl;

	//CTest tst1;
	//CTest tst2(tst1);

	CTest tst3(10);
	CTest tst4(tst3);

	system("pause");
	return 0;
}
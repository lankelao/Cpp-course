#include<iostream>
using namespace std;

//���캯������������������ṩһ��Ĭ�ϵ��޲εĹ��캯�������������Ϊ��
//���������ǵ�ǰ����,û�з���ֵ������������Ҳ����û��
//���캯����������ʼ�����Ա����(��Ա���ԣ�
//��������ʱ��,�Զ�����
//���캯�������ж��������֮���Ǻ������صĹ�ϵ�������������ִֻ��ĳһ�����캯��


// �����������ͷų�Ա����ռ�
// ���� ������ ~���� ���޲������޷���ֵ����������ֻ��һ��
//. ������������ڽ�����ʱ���Զ�����
class CTest{
public:
	int m_nAge;
	int m_nSex;
	int *m_p;
public:
	CTest(){
		m_nAge = 10;

		m_p = new int(10);
	}
	CTest(int age){
	
		m_nAge = age;
		m_p =NULL;
	}
	CTest(int age, int sex){
		m_nAge = age;
		m_nSex = sex;
	}

	// ����
	~CTest(){
		cout<<"~CTest"<<endl;
		if(m_p){
			delete m_p;
			m_p=NULL;
		}
	}

};


int main(){
	//CTest tst;  //���� �޲εĹ��캯��

	//cout<< tst.m_nAge<<endl;

	//CTest tst2(12);

	/*CTest *pTst = new CTest(12,1);

	cout<<pTst->m_nAge<<endl;
	cout<<pTst->m_nSex<<endl;

	delete pTst;*/

	{
		CTest tst;
	}

	system("pause");
	return 0;
}
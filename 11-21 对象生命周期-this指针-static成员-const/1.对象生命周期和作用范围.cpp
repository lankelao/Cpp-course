#include<iostream>
using namespace std;

class CTest{
public:
	int m_a;
public:
	CTest(){
		m_a = 10;
		cout<<"CTest()"<<endl;
	
	}

	CTest(int a){
		m_a = 20;
		cout<<"CTest(int a)"<<endl;
	
	}
	~CTest(){
		cout<<"~CTest()"<<endl;
	
	}

};

// 3. ȫ�ֶ��� ���������Զ�Ϊ�������ռ䣬ֱ�� �������
//CTest tst2;

// 4. ��̬ȫ�ֶ����������ڣ����������Զ�Ϊ�������ռ䣬ֱ�� �������
//static CTest tst3;
//��̬���÷�Χ���ļ�������ȫ�ֶ������÷�Χ����������

CTest * ptst=NULL;
void show(){

	static CTest tst;  //�������ڣ���һ�ε��ú�����ʱ�򴴽�����ֱ���������,���ڴ���ֻ��һ��
	ptst=&tst;
}

// 5 .��ʱ����
CTest GetTest(){
	CTest tst;
	return tst;
}

int main(){
	//show();
	//cout<< ptst->m_a<<endl;;
	//cout<<"-----------------"<<endl;
	////CTest tst;   //1. �ֲ�����ջ����

	////CTest *pTst =new CTest;  //2. new ������������ ֱ�� ����delete
	//show();

	//CTest tst();  //��Ҫ����д��
	//cout<<"----------------"<<endl;
	//CTest (2);   //5.��ʱ������������:��ǰ��һ�У�ֱ������;
	//cout<<"----------------"<<endl;


	cout<<"----------------"<<endl;
	GetTest();
	cout<<"----------------"<<endl;


	system("pause");
	return 0;
}
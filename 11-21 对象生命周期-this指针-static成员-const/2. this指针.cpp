#include<iostream>
using namespace std;
/*
���Ա���ԣ�ռ�ö�����ڴ�ռ䣬�������ʱ����,���������ڶ��

���Ա��������ռ�ö�����ڴ�ռ䣬ռ�õ���Ӧ�ó�����ڴ�ռ䣬�ڱ����ھʹ��ڣ�������ֻ��һ��
*/
class CTest{
public:
	int m_a;
public:
	CTest(int a){
		m_a = a;
	
	}

	//this ָ��
	//  CTest *const this;
	// ���зǾ�̬��Ա��������һ��Ĭ�ϵ������Ĳ��� ��thisָ��  CTest *const this;
	// �������ӳ�Ա���� �ͳ�Ա�������������ĸ���������˺���this��ָ�����ĸ�����
	void show(/* CTest *const this */){
		cout<<this->m_a<<endl;
	}
	void play(/* CTest *const this */){
		cout<<"play()"<<endl;
		cout<<this->m_a<<endl;
	}
};


int main(){
	//CTest tst;

	//cout<< sizeof(tst)<<endl;
	//cout<< sizeof(CTest) <<endl;  //1: ռλ������


	//CTest tst;
	//cout<< sizeof(tst)<<endl;
	//cout<< sizeof(CTest) <<endl;  //1: ռλ������


	//CTest tst1(1);
	//tst1.show();

	//CTest tst2(2);
	//tst2.show();


	CTest *p=NULL;
	//p->m_a = 10;
	p->play();




	system("pause");
	return 0;
}
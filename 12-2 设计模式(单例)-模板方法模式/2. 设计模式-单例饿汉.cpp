#include<iostream>
using namespace std;

//����ģʽ��
//1.��ǰ���������ֻ����һ��ʵ��
//2.�ܹ������������ʵ���������ǵ����ߴ���ʵ����
//3.��ȫ�ֿ������ʵ��


//����ʽ�����򴴽�֮�����ͻ��Ψһ��ʵ�������������ռ任ʱ������(���߳�û������)
class CObject{
public:
	int m_a;
private:
	static CObject *m_pObjec;
private:
	CObject(){
		m_a = 10;
	}
	CObject(const CObject &obj){
		this->m_a = obj.m_a;
	}
	~CObject(){
		
	}
public:
	static CObject *GetInstance(){

		return m_pObjec;
	}
};
CObject *CObject::m_pObjec = new CObject;
int main(){

	CObject *p1 = CObject::GetInstance();
	CObject *p2 = CObject::GetInstance();

	p1->m_a = 30;
	cout<< p2->m_a <<endl;


	system("pause");
	return 0;
}
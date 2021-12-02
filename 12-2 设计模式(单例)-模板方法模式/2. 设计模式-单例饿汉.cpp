#include<iostream>
using namespace std;

//单例模式：
//1.当前这个类有且只能有一个实例
//2.能够自主创建这个实例（而不是调用者创建实例）
//3.向全局开放这个实例


//饥汉式：程序创建之初，就会把唯一的实例创建出来，空间换时间做法(多线程没有问题)
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
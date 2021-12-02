#include<iostream>
using namespace std;

//单例模式：
//1.当前这个类有且只能有一个实例
//2.能够自主创建这个实例（而不是调用者创建实例）
//3.向全局开放这个实例


//懒汉式：在用到的时候去创建唯一实例，用时间换空间的做法；多线程会有问题（加锁解决）
class CObject{
public:
	int m_a;
private:
	static int ObjCount;//需要类外初始化
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
public://通过接口让类外调用,得是公共的
	static CObject *GetInstance(){//CObject GetInstance有临时对象的问题，用指针，static不通过对象调用
		
		if(ObjCount>=1){
			return m_pObjec;
		}
		ObjCount++;
		m_pObjec = new CObject;
		return m_pObjec;
	}
	static void Destroy(CObject *&p){
		if(m_pObjec){
			delete m_pObjec;
			m_pObjec = NULL;
		}
		p = NULL;
	}
};
int CObject::ObjCount = 0;//初始化
CObject *CObject::m_pObjec = NULL;

int main(){

	//CObject o1;
	//CObject o2;//现在能定义多个对象，办法：在类内创建，在类外调用

	CObject *pObject1 = CObject::GetInstance();
	//ObjCount = 0;	//ObjCount不能定义成全局的，不然谁都能改了，然后可以创建多个对象
	CObject *pObject2 = CObject::GetInstance();//又有了多个对象，想让它只有一个，加个计数器,
	//加完计数器之后是一个对象，但其他人不能获取了，


	//CObject obj1 = *pObject1;//拷贝构造还是能创建多个对象，可以加私有析构
	//CObject *pobj3 = new CObject(*pObject1);
	//delete pobj3;//不允许调用析构


	pObject1->m_a = 20;

	cout<<pObject2->m_a<<endl;

	CObject::Destroy(pObject2);
	if(pObject2){
		cout<<pObject2->m_a<<endl;
	}

	CObject::Destroy(pObject1);
	if(pObject1){
		cout<<pObject1->m_a<<endl;
	}


	system("pause");
	return 0;
}
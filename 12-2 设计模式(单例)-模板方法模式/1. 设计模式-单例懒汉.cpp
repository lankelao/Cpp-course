#include<iostream>
using namespace std;

//����ģʽ��
//1.��ǰ���������ֻ����һ��ʵ��
//2.�ܹ������������ʵ���������ǵ����ߴ���ʵ����
//3.��ȫ�ֿ������ʵ��


//����ʽ�����õ���ʱ��ȥ����Ψһʵ������ʱ�任�ռ�����������̻߳������⣨���������
class CObject{
public:
	int m_a;
private:
	static int ObjCount;//��Ҫ�����ʼ��
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
public://ͨ���ӿ����������,���ǹ�����
	static CObject *GetInstance(){//CObject GetInstance����ʱ��������⣬��ָ�룬static��ͨ���������
		
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
int CObject::ObjCount = 0;//��ʼ��
CObject *CObject::m_pObjec = NULL;

int main(){

	//CObject o1;
	//CObject o2;//�����ܶ��������󣬰취�������ڴ��������������

	CObject *pObject1 = CObject::GetInstance();
	//ObjCount = 0;	//ObjCount���ܶ����ȫ�ֵģ���Ȼ˭���ܸ��ˣ�Ȼ����Դ����������
	CObject *pObject2 = CObject::GetInstance();//�����˶������������ֻ��һ�����Ӹ�������,
	//���������֮����һ�����󣬵������˲��ܻ�ȡ�ˣ�


	//CObject obj1 = *pObject1;//�������컹���ܴ���������󣬿��Լ�˽������
	//CObject *pobj3 = new CObject(*pObject1);
	//delete pobj3;//�������������


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
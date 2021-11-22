#include<iostream>
using namespace std;

class CHand{
public:
	void Move(){
		cout<<"�� ����ž��~~"<<endl;
	}
};

class CComputer{
public:
	void Complie(){//���빦��
		cout<<"���ڱ��롢���ɴ���..."<<endl;
	}
};

class CFriend{
public:
	void play(){
		cout<<"���ֵ��Ϻţ�������������Ϸ..."<<endl;
	}
};

class CPeople{
public:
	CHand m_hand;//����һ���ֵĶ���
	CFriend *m_pFri;//������ʱ���и����ѵ�ָ�룬��Ҫ��������ʼ��
	CPeople(){
		m_pFri = NULL;
	}
	~CPeople(){//���ⲻ��delete m_pFri,��Ϊ�˺�����û����������Լ����ϵ

	}
public:
	void Clap()
	{
		m_hand.Move();
		cout<<"������������~~"<<endl;
	}
	void Code(CComputer *comp){//��Ҫ�õ��� Ҫͨ������
		if(comp){
			m_hand.Move();
			cout<<"����ž�����ô���"<<endl;

			comp->Complie();//����
			cout<<"���ɿ�ִ�г���"<<endl;
		}
	}
	void SetFriend(CFriend *pFri){//�����ѣ�ͨ��һ��������д��һ����������ֵ
		m_pFri = pFri;
	}
	void PlayWangZhe(){
		if(m_pFri){
			m_pFri->play();
		}
		cout<<"�����ڴ�����..."<<endl;
	}
};

class CFamily{
public:
	CPeople *m_pPeo[10];//��һ���˵�����
public:
	CFamily(){
		for(int i=0;i<10;i++){
			m_pPeo[i] = NULL;//��ʼֵΪNULL
		}
	}
	~CFamily(){//�ۺ�����������Լ����ϵ����ͥ���ڵ�ʱ����Ҳ������
		for(int i=0;i<10;i++){
			if(m_pPeo){
				delete m_pPeo[i];
				m_pPeo[i] = NULL;
			}
		}
	}
public:
	void PushPeople(CPeople *pPeo){//��ͥ�������
		for(int i=0;i<10;i++){
			if(m_pPeo[i] == NULL){//�ĸ�λ����NULL�������
				m_pPeo[i] = pPeo;
				return;//һ��return
			}
		}
	}
	void AllPeopleCode(CComputer *computer){
		for(int i=0;i<10;i++){
			if(m_pPeo[i]){
				m_pPeo[i]->Code(computer);
			}
		}
	}
};

int main()
{
//--------------------------��ϣ����ϣ�------------------------
	CPeople people;//����һ���Լ�
	people.Clap();//���ù��ƹ���

//--------------------------����-------------------------------
	CComputer *pComp = new CComputer;
	people.Code(pComp);

	delete pComp;//����û�ˣ�people.Code(pComp)Ҳ�Ͳ������
	pComp = NULL;
	people.Code(pComp);
//--------------------------����-------------------------------
	CFriend *pFri = new CFriend;//����һ������
	people.SetFriend(pFri);//�Ƚ�һ������people.m_pFri = pFri
	people.PlayWangZhe();

	delete pFri;
	pFri = NULL;
	people.m_pFri = NULL;//����û�ˣ�����ָ��Ҳ����
	people.PlayWangZhe();//����û�ˣ��Լ���Ȼ��������Ϸ
//--------------------------�ۺ�-------------------------------
	CFamily family;
	CPeople *pPeo1 = new CPeople;
	CPeople *pPeo2 = new CPeople;
	CPeople *pPeo3 = new CPeople;
	CPeople *pPeo4 = new CPeople;

	family.PushPeople(pPeo1);
	family.PushPeople(pPeo2);
	family.PushPeople(pPeo3);
	family.PushPeople(pPeo4);

	CComputer *pComp1 = new CComputer;
	family.AllPeopleCode(pComp1);

	system("pause");
	return 0;
}
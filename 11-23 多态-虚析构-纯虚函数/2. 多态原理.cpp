#include<iostream>
using namespace std;
//������-------��̬ԭ��1
/*�麯��ָ�룺����ָ�룬ֻҪ���д����麯�����ڶ�������ʱ�򣬷�����ڴ�ռ�ͻ���4���ֽڣ���ָ����һ������,
_vfptr		�����ÿ��Ԫ����һ������ָ�룬����ָ��ָ������麯�����ڹ��캯����ʼ���б��н��г�ʼ����ָ������
			�����б��������ڶ���ģ���������ʱ��Ŵ��ڣ��ڶ������ռ��ǰ4���ֽ�

�麯���б�  ����������ģ������ھʹ���

�麯�����ã�	ͨ���麯��ָ��->�麯���б��������Ҷ�Ӧ�ĺ���ָ��,->����ָ��ȡ���þ�����麯��
*/
//�̳й�ϵ��-----��̬ԭ��2
//���ǣ������麯����д�˸�����麯�������麯���б��л��滻��������麯��
class CFather{
public:
	CFather(){
		cout<<"fa"<<endl;
	}
public:
	virtual void show(){
		cout<<"CFather::show"<<endl;
	}
	virtual void code(){
		cout<<"CFather::code"<<endl;
	}
};

class CSon:public CFather{
public:
	CSon(){
		cout<<"son"<<endl;
	}
public:
	virtual void play(){
		cout<<"CSon::play"<<endl;
	}
	virtual void show(){
		cout<<"CSon::show"<<endl;
	}
};


int main()
{
//�̳в����̳��˸����Ա���̳����麯���б�
//new���ĸ����࣬vfptr���վ�ָ���ĸ�������麯���б�
	CFather *pFa = new CSon;
	pFa->show();		//"CSon::show"
	//pFa->play();
	CSon *pSon = new CSon;
	pSon->play();
//---------------------------------------------------
	typedef void (*P_FUN)();
	P_FUN p_fun1 = (P_FUN)*(((int*)(*(int*)pFa))+0);
	P_FUN p_fun2 = (P_FUN)*(((int*)(*(int*)pFa))+1);
	P_FUN p_fun3 = (P_FUN)*(((int*)(*(int*)pFa))+2);
	P_FUN p_fun4 = (P_FUN)*(((int*)(*(int*)pFa))+3);

	(*p_fun1)();
	(*p_fun2)();
	(*p_fun3)();
	(*p_fun4)();

	system("pause");
	return 0;
}

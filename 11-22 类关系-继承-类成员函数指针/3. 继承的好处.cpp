#include<iostream>
using namespace std;

//�̳У��������й����ĳ�Ա��ȡ�����γɸ��࣬�������ȥʹ�ø����еĹ�����Ա������˴���ĸ����Ժ���չ��
//�������ָ��ָ������Ķ��󣬷���������
class People{
public:
	void play(){
		cout<<"playplay"<<endl;
	}
};

class CYellowPeople:public People{
public:
	//void play(){
	//	cout<<"playplay"<<endl;
	//}
};

class CWhitePeople:public People{
//public:
//	void play(){
//		cout<<"playplay"<<endl;
//	}
};

class CBlackPeople:public People{
public:
	//void play(){
	//	cout<<"playplay"<<endl;
	//}
};


int main()
{
	CYellowPeople p1;
	p1.play();
	CWhitePeople p2;
	p2.play();
	CBlackPeople p3;
	p3.play();


	system("pause");
	return 0;
}
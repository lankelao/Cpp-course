#include<iostream>
using namespace std;

//�ܽ��̬    ��̬��ȱ�㣺1.Ч�ʵ�2.ռ�ö���ռ�3.��ȫ�Ե�
class CFather{    
public:
	virtual void play() = 0;		//���麯�����������ʵ���������
};

class CSon:public CFather{
public:
	virtual void play(){
		cout<<"play"<<endl;
	}
};

int main()
{
	CSon son;
	son.play();

	//CFather fa;	//�����ࣺ���ڴ��麯���������������
					//�ӿ��ࣺ�麯�����Ǵ��麯���������������			
	system("pause");
	return 0;
}



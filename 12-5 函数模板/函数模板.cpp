#include<iostream>
#include<typeinfo>
using namespace std;

//template:����ģ��Ĺؼ���
//typename:����ģ�����͵Ĺؼ���
//TT		  ��ͨ�����ͣ��Լ����壩
//< typename TT>:ģ��Ĳ����б�
template< typename TT >
TT Add(TT a,TT b){
	TT c = a + b;
	return c;
}

template< typename TT,typename KK >
TT Add(TT a,TT b,KK d){
	KK c = a + b + d;
	return c;
}

template< typename TT>
void show1(TT a,int b = 10);

//����������ģ����ʹ��Ĭ��ģ�����
template< typename TT>
TT show2(){
	cout<< "show2" <<endl;
	return 20;
}

template< typename TT>
void show3(int a){
	TT f = 30;
	cout<< "show3" <<endl;
}

template< typename TT>
void show4(TT a){
	TT f = a;
	cout<< "show4" <<endl;
}

template< typename TT,typename KK>
void show5(TT a){
	TT f = a;
	KK e = 20;
	cout<< "show4" <<endl;
}

int main(){

	int a = 10,b = 20;
	Add(a,b);
	double c = 1.0,d = 2.0;
	Add(c,d);
	Add(a,b,d);

	char a1 = 48;
	//show1(a1);
	show1(a1,20);


	show2<int>();//�ֶ�ָ��ģ������
	cout<< typeid(show2<int>()).name() <<endl;
	cout<< typeid(show2<char>()).name() <<endl;

	show3<double>(20);

	show4<char>(20);

	show5<char,double>(20);

	system("pause");
	return 0;
}

template< typename TT>
void show1(TT a,int b){
	cout<< a <<endl;
	cout<< b <<endl;
}
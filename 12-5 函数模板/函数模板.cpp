#include<iostream>
#include<typeinfo>
using namespace std;

//template:定义模板的关键字
//typename:定义模板类型的关键字
//TT		  ：通用类型（自己定义）
//< typename TT>:模板的参数列表
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

//仅允许在类模板上使用默认模板参数
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


	show2<int>();//手动指定模板类型
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
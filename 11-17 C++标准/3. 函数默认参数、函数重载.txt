#include<iostream>
using namespace std;
//C++中可以在声明函数时定义缺省函数值来减少一些编程工作

//void Show(int a,int b,int c,int d)
void Show(int a = 1,int b = 0,int c = 2,int d = 1)//要定义缺省值后买你一定要给，前面可以不给
{
	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
}
void Show1(int a,int b,int c = 2,int d = 1);


int main()
{
	Show();
	Show(100,200);
	Show(1,2,3,4);
	//Show(,,30,40);//从左到右传，前面一定要给

	Show1();
	Show1(100,200);
	Show1(1,2,3,4);

system("pause");  
}
void Show1(int a,int b,int c,int d)
{
	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
}
//--------------------------函数重载---------------------------------
//函数重载：得在同一个作用域，名字一样，参数列表不同（参数类型或者个数）
#include<iostream>
using namespace std;

void Area(int r)
{
	cout << 3.14*r*r <<endl;
}
void Area(int a,int b)
{
	cout << a*b <<endl;
}
void Area(char *r)
{
	cout << r <<endl;
}
int main()
{
	Area(1);
	Area(2,3);
	Area("asdsf");


	system("pause"); 
	return 0;
}
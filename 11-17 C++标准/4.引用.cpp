#include<iostream>
using namespace std;


//引用是给某个变量起别名
int main()
{
	int a = 100;
	int &k = a; //定义一个引用，一定要初始化
	k = 200;
	cout << a << endl;


system("pause");  
}
//对引用进行操作，实际上就是对被引用的变量进行操作
//引用不是值，不占存储空间，声明引用时，目标得储存状态不会改变
//引用一旦被初始化，就不能再引用其他空间

//----------------------------引用的应用-------------------------------------
#include<iostream>
using namespace std;


void Swap(int a,int b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}
void Swap(int* a,int* b)
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}
void Swap1(int& a,int& b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}
int main()
{
	int a = 100;
	int b = 200;
	Swap(a,b);  //值传递       不可交换
	Swap(&a,&b);  //地址传递		可交换
	Swap1(a,b);  //引用传递		可交换

//函数传递方式的选择？是否要修改传入的内容\
	只是使用-->值传递(尽量不用)，需要修改-->地址，引用
//什么时候用指针？\
	new malloc 需要用地址传递
//什么时候用引用？\
	单一变量使用引用
system("pause");  
}
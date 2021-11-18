#include<iostream>
using namespace std;


int main()
{
	int *p = new int;  //在堆区分配一个int空间
	cin >> *p;
	cout << *p <<endl; //删除p指向的空间，p还是存在
	delete p;
	p = 0;
//--------------------------new一个数组----------------------------------
	int *arr = new int[10]; //分配一个int数组
	delete[] arr;	//删除数组 要delete[]
	arr = 0;
//--------------------------new数组问题----------------------------------
	int *arr = new int(10); //分配一个int  用10初始化这块空间
	arr[1] = 123;			//越界，只有arr[0]一个空间
	delete[] arr;	
	arr = 0;
//--------------------------new一个结构体--------------------------------
	struct Node       //c++中不用再typedef
	{
		int a;
		char c;
	};
	Node *pNode = new Node;
	delete pNode;
	pNode = 0;

system("pause");  //加暂停  在cmd命令行，输入命令
}
#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;


int main()
{
//----------------------------范围for----------------------------------
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	for(int i=0;i<10;i++)
	{
		cout<< arr[i] <<" ";
	}
	//c++11  范围for
	for(int nVal : arr)     //自动从头遍历到尾
	{
		cout<< nVal <<" ";   //nval == arr[i]
	}

//----------------------------bool类型----------------------------------
	BOOL bFlag = FALSE;     // 再Windows.h头文件里 TRUE FLASE是宏，BOOL是typedef的int
	bool bFlag = false;     //在c++中，有bool类型,一个字节，值是true(1)和flase(0)

//----------------------------string----------------------------------
	string str = "aaa";
	cout << str <<endl;
	str = "bbbbbbb";
	cout << str <<endl;
	cout << (str == "cccccc") <<endl;

	string str1;
	str1 = str + "kkkkk";  //拼接字符串
	cout << str1 <<endl;
	str1 += "pppp";        //也是拼接字符串
	cout << str1 <<endl;
system("pause");  //加暂停  在cmd命令行，输入命令
}
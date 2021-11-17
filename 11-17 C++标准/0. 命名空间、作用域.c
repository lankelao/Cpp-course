#include<iostream>
using namespace std;

int nAge = 10;
int main()
{
	int nAge = 20;
	cout << nAge << endl; 
//::作用域运算符  ::前没有内容代表全局
	cout << ::nAge <<endl; 
	//cout << std::nAge <<endl; 也可以不用using namespace std,直接用std::打开命名空间
	return 0;
}
//------------------------使用作用域------------------------------
#include<iostream>
using namespace std;

namespace Bird
{
	int nAge = 10;
}
namespace Person
{
	int nAge = 20;
}
int main()
{
	cout << Person::nAge << endl; //打开Person作用域
	return 0;
}

//----------------------------使用命名空间-------------------------------
#include<iostream>
using namespace std;

namespace Bird//定义一个命名空间
{
	int nAge = 10;
}
namespace Person
{
	int nAge = 20;
}

using namespace Bird;  //打开Bird命名空间也可以
int main()
{
	cout << nAge << endl; 
	return 0;
}
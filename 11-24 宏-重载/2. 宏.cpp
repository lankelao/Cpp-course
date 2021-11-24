//program once   //直接告诉编译器，当前文件只包含一次，解决头文件重复包含问题
#include<iostream>
using namespace std;
//宏：替换,编译前就完成了替换工作
#define N 10
//可以替一个值或者函数
#define AA(PARAM) 	\
for(int i=0;i<PARAM;i++)\
	{\
		cout<<i<<endl;\
	}
int main(){
	//for(int i=0;i<N;i++){
	//	cout<<i<<endl;
	//}
	AA(5)

	system("pause");
	return 0;
}
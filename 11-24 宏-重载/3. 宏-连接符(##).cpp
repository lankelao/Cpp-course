#include<iostream>
using namespace std;

//##:Á¬½Ó·û
#define CC(THIS_CLASS)\
	THIS_CLASS tst##THIS_CLASS;\
	tst##THIS_CLASS.show();

class CTest1{
public:
	void show(){
		cout<<"CTest1"<<endl;
	}
};
class CTest2{
public:
	void show(){
		cout<<"CTest2"<<endl;
	}
};
int main(){

	CC(CTest1)
	CC(CTest2)

	system("pause");
	return 0;
}
#include<iostream>
using namespace std;
//类外重载：注意与类内的冲突问题
class CTest{
public:
	int m_a;
	CTest(){
		m_a = 10;
	}
	int operator+(int a){
		return m_a + a;
	}
};
int operator+(int a,CTest & tst){
	return a+tst.m_a;
}
int operator++(CTest &tst){//左++
	return ++tst.m_a;
}
int operator++(CTest &tst,int){//右++
	return tst.m_a++;
}
ostream& operator<<(ostream& os,CTest& tst){
	os<<tst.m_a;
	return os;
}
istream& operator>>(istream& is,CTest& tst){
	is>>tst.m_a;
	return is;
}
int main(){
	CTest tst;
	tst + 10;	//这是类内重载了可以
	10 + tst;	//这个没有重载，需要类外重载
	++tst;
	tst++;
	cout<<tst<<endl;
	cin>>tst;
	cout<<tst<<endl;

	system("pause");
	return 0;
}
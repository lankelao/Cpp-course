#include<iostream>
using namespace std;
//�������أ�ע�������ڵĳ�ͻ����
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
int operator++(CTest &tst){//��++
	return ++tst.m_a;
}
int operator++(CTest &tst,int){//��++
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
	tst + 10;	//�������������˿���
	10 + tst;	//���û�����أ���Ҫ��������
	++tst;
	tst++;
	cout<<tst<<endl;
	cin>>tst;
	cout<<tst<<endl;

	system("pause");
	return 0;
}
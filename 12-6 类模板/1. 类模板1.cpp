#include<iostream>
#include<typeinfo>//�鿴����
using namespace std;
//������ģ�壬��ģ����Ը�Ĭ������<typename TT,typename KK=int>,������������ָ�������ܼ��
template<typename TT=int,typename KK=double>
class CTest{
public:
	TT m_a;
	KK m_k;
	CTest(){
		m_a = 10;
	}
	CTest(TT t,KK k){
		m_a = t;
		m_k = k;
	}
public:
	void show(TT tt){
		TT t = 20;
		cout<<t<<"  "<<typeid(t).name()<<endl;
		cout<<tt<<"  "<<typeid(tt).name()<<endl;
	}
	template<typename MM>
	void Get(/*MM mm*/){
		cout<<m_a<<"  "<<typeid(m_a).name()<<endl;
		cout<<m_k<<"  "<<typeid(m_k).name()<<endl;
		MM m = 30;
		cout<<m<<"  "<<typeid(m).name()<<endl;
	}
	template<typename NN>
	void play(TT t,KK k);
};


template<typename TT,typename KK>
template<typename NN>//����˳����Ҫע�⣬����ģ��֮�価����Ҫ�ж���
void CTest<TT,KK>::play(TT t,KK k){

	cout<<(char)(m_a+t)<<"  "<<typeid(m_a).name()<<endl;
	cout<<m_k+k<<"  "<<typeid(m_k).name()<<endl;

	NN n = 50;
	cout<<n<<"  "<<typeid(n).name()<<endl;
}
int main(){
	
	//CTest<int>tst;	//list<int>lst;��ǰ��listҲ��ģ����
	//cout<< tst.m_a <<endl;
	//tst.show(90);

	//CTest<double>tst2(3.14);
	//tst2.Get();

	//CTest<int,double>tst(10,3.14);
	//tst.Get();
	//tst.play();

	//CTest<char,int>tst2('A',30);
	//tst2.play();

	CTest<char,int>tst2('A',30);
	tst2.play<long>(10,3.14);
	//tst2.Get<long>();

	system("pause");
	return 0;
}

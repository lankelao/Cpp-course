#include<iostream>
#include<typeinfo>//查看类型
using namespace std;
//区别函数模板，类模板可以给默认类型<typename TT,typename KK=int>,从右向左依次指定，不能间断
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
template<typename NN>//这里顺序需要注意，函数模板之间尽量不要有东西
void CTest<TT,KK>::play(TT t,KK k){

	cout<<(char)(m_a+t)<<"  "<<typeid(m_a).name()<<endl;
	cout<<m_k+k<<"  "<<typeid(m_k).name()<<endl;

	NN n = 50;
	cout<<n<<"  "<<typeid(n).name()<<endl;
}
int main(){
	
	//CTest<int>tst;	//list<int>lst;以前的list也是模板类
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

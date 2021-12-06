#include<iostream>
#include<typeinfo>
using namespace std;

template<typename TT>
class AA{
public:
	TT m_t;
	AA(){
		m_t = 20;
	}
};
template<typename KK>
class BB{
public:
	AA<KK>m_a;
};
template<typename MM,typename NN>
class CC{
public:
	MM m_m;
	NN m_n;
	CC(MM m,NN n){
		m_m = m;
		m_n = n;
	}
};


int main(){
	
	BB<int>bb;
	cout<<bb.m_a.m_t<<"--"<<typeid(bb.m_a.m_t).name()<<"--"<<typeid(bb.m_a).name()<<endl;

	AA<int> aa;
	CC<AA<int>,int>cc(aa,20);
	cout<< cc.m_m.m_t <<endl;
	cout<< cc.m_n <<endl;

	system("pause");
	return 0;
}

/*
STL:Standard Template Library 标准模板库
6组件：
1.容器	container如链表
2.迭代器	容器的迭代器 iterator
3.算法	algorithm
4.容器适配器	adapter本质也是容器，修改后变成特殊容器有特殊的用途
5.分配器/空间适配器	allocator主要分配管理空间
6.仿函数	Function Object本质是一个类，通过类实现函数类似的功能，重载了(),operator()
*/

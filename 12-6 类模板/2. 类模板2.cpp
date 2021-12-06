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
STL:Standard Template Library ��׼ģ���
6�����
1.����	container������
2.������	�����ĵ����� iterator
3.�㷨	algorithm
4.����������	adapter����Ҳ���������޸ĺ��������������������;
5.������/�ռ�������	allocator��Ҫ�������ռ�
6.�º���	Function Object������һ���࣬ͨ����ʵ�ֺ������ƵĹ��ܣ�������(),operator()
*/

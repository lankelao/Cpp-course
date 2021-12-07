#include<iostream>
#include<list> 
#include<algorithm>
using namespace std;
/*
STL:标准模板库
容器：
	1.序列性容器：list vecter deque
		保持了元素在容器中的原始位置，允许在容器中指定插入的位置，每个元素都有固定的位置，取决于插入的时间地点，和元素的值无关。
	2.关联性容器：map set hash_map
		元素插入的位置取决于特定的排序规则

迭代器
算法
容器适配器
分配器(空间分配器)
仿函数
*/



void show(int a){
	cout<<a<<"  ";
}

bool rule(int a,int b){
	return a>b;
}

int main(){
	list<int>lst;
	lst.push_back(1);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(5);
	lst.push_back(2);
	lst.push_back(2);
	lst.sort(&rule);
	::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	//lst.remove(5);//移除所有5
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	//lst.unique();//连续相同的值保留一个
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;

	//lst.sort();//默认升序
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	//lst.reverse();//翻转
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;

	//lst.sort(&rule);
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;

	list<int>lst2;
	lst2.push_back(60);
	lst2.push_back(20);
	lst2.push_back(50);
	lst2.sort(&rule);
	::for_each(lst2.begin(),lst2.end(),&show);cout<<endl;
	
	//lst.splice(++lst.begin(),lst2);//剪切插入
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	//::for_each(lst2.begin(),lst2.end(),&show);cout<<endl;

	//lst.splice(++lst.begin(),lst2,++lst2.begin());//剪切某个值插入
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	//::for_each(lst2.begin(),lst2.end(),&show);cout<<endl;

	//lst.splice(++lst.begin(),lst2,++lst2.begin(),lst2.end());//剪切某个范围插入
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	//::for_each(lst2.begin(),lst2.end(),&show);cout<<endl;

	//lst.splice(++lst.begin(),lst,--lst.end());
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;

	//lst.splice(++lst.begin(),lst,++(++(lst.begin())),lst.end());
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;

	//lst.merge(lst2);
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	//::for_each(lst2.begin(),lst2.end(),&show);cout<<endl;

	//lst.merge(lst2,&rule);
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	//::for_each(lst2.begin(),lst2.end(),&show);cout<<endl;

	//lst.swap(lst2);
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	//::for_each(lst2.begin(),lst2.end(),&show);cout<<endl;
	swap(lst,lst2);
	::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	::for_each(lst2.begin(),lst2.end(),&show);cout<<endl;

	system("pause");
	return 0;
}
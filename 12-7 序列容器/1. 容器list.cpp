#include<iostream>
#include<list> 
#include<algorithm>
using namespace std;
/*
STL:��׼ģ���
������
	1.������������list vecter deque
		������Ԫ���������е�ԭʼλ�ã�������������ָ�������λ�ã�ÿ��Ԫ�ض��й̶���λ�ã�ȡ���ڲ����ʱ��ص㣬��Ԫ�ص�ֵ�޹ء�
	2.������������map set hash_map
		Ԫ�ز����λ��ȡ�����ض����������

������
�㷨
����������
������(�ռ������)
�º���
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
	//lst.remove(5);//�Ƴ�����5
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	//lst.unique();//������ͬ��ֵ����һ��
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;

	//lst.sort();//Ĭ������
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	//lst.reverse();//��ת
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;

	//lst.sort(&rule);
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;

	list<int>lst2;
	lst2.push_back(60);
	lst2.push_back(20);
	lst2.push_back(50);
	lst2.sort(&rule);
	::for_each(lst2.begin(),lst2.end(),&show);cout<<endl;
	
	//lst.splice(++lst.begin(),lst2);//���в���
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	//::for_each(lst2.begin(),lst2.end(),&show);cout<<endl;

	//lst.splice(++lst.begin(),lst2,++lst2.begin());//����ĳ��ֵ����
	//::for_each(lst.begin(),lst.end(),&show);cout<<endl;
	//::for_each(lst2.begin(),lst2.end(),&show);cout<<endl;

	//lst.splice(++lst.begin(),lst2,++lst2.begin(),lst2.end());//����ĳ����Χ����
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
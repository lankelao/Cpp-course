#include<iostream>
#include<list>
#include<algorithm>//有个全局函数,也可以遍历
using namespace std;

void show(int a){
	cout<<a<<"  ";
}

struct Node{
	int m_a;
	int m_b;
	Node(){
		m_a = 10;
		m_b = 20;
	}
};
void showNode(Node* p){
	cout<<p->m_a<<"  "<<p->m_b<<"  ";
}
int main(){
	//list<int> lst;	//定义一个链表
	//lst.push_back(1);
	//lst.push_back(2);
	//lst.push_back(3);

	//lst.push_front(4);//头添加
	//lst.push_front(5);
	//lst.push_front(6);

	//list<int>::iterator ite = lst.begin();    //定义一个迭代器，也是一个类，可以当指针来用,返回头节点迭代器
	//while (ite != lst.end()){//1.遍历
	//	cout<<*ite<<"  ";
	//	ite++;
	//}
	//::for_each(lst.begin(),lst.end(),&show);		//2.也可以遍历

	//lst.pop_back();//尾删除
	//::for_each(lst.begin(),lst.end(),&show);	
	//lst.pop_front();//头删除
	//::for_each(lst.begin(),lst.end(),&show);	

	//list<int>::iterator ite1 = ++lst.begin(); //ite1指向第二个
	//list<int>::iterator ite2 = lst.insert(ite1,10);//insert也是迭代器，有返回值，返回新插入的节点
	//cout<<*ite2<<endl;
	//::for_each(lst.begin(),lst.end(),&show);	

	//ite2 = lst.erase(ite2);//lst.erase(ite2)，在哪个位置擦除，删除完之后迭代器指针没有移动，erase返回删除节点的下一个节点
	//::for_each(lst.begin(),lst.end(),&show);	
	//cout<<lst.front()<<endl;;//获得头节点的元素,相当于
	//list<int>::iterator ite3 = lst.begin();
	//cout<<(*ite3)<<endl;

	//cout<<lst.back()<<endl;
	//list<int>::iterator ite4 = lst.end();
	//--ite4;
	//cout<<(*ite4)<<endl;

	//list<int>::iterator ite5 = ::find(lst.begin(),lst.end(),3);//返回节点的迭代器，找不到返回end；
	//cout<<(*ite5)<<endl;


	list<Node*> lst2;
	Node*p1 = new Node;
	lst2.push_back(p1);
	Node*p2 = new Node;
	p2->m_a = 30;
	p2->m_b = 40;
	lst2.push_back(p2);

	list<Node*>::iterator itee = lst2.begin();
	while (itee != lst2.end()){
		cout<<(*itee)->m_a<<"  "<<(*itee)->m_b<<"  ";
		itee++;
	}
	::for_each(lst2.begin(),lst2.end(),&showNode);

	system("pause");
	return 0;
}
#include<iostream>
#include<list>
#include<algorithm>//�и�ȫ�ֺ���,Ҳ���Ա���
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
	//list<int> lst;	//����һ������
	//lst.push_back(1);
	//lst.push_back(2);
	//lst.push_back(3);

	//lst.push_front(4);//ͷ���
	//lst.push_front(5);
	//lst.push_front(6);

	//list<int>::iterator ite = lst.begin();    //����һ����������Ҳ��һ���࣬���Ե�ָ������,����ͷ�ڵ������
	//while (ite != lst.end()){//1.����
	//	cout<<*ite<<"  ";
	//	ite++;
	//}
	//::for_each(lst.begin(),lst.end(),&show);		//2.Ҳ���Ա���

	//lst.pop_back();//βɾ��
	//::for_each(lst.begin(),lst.end(),&show);	
	//lst.pop_front();//ͷɾ��
	//::for_each(lst.begin(),lst.end(),&show);	

	//list<int>::iterator ite1 = ++lst.begin(); //ite1ָ��ڶ���
	//list<int>::iterator ite2 = lst.insert(ite1,10);//insertҲ�ǵ��������з���ֵ�������²���Ľڵ�
	//cout<<*ite2<<endl;
	//::for_each(lst.begin(),lst.end(),&show);	

	//ite2 = lst.erase(ite2);//lst.erase(ite2)�����ĸ�λ�ò�����ɾ����֮�������ָ��û���ƶ���erase����ɾ���ڵ����һ���ڵ�
	//::for_each(lst.begin(),lst.end(),&show);	
	//cout<<lst.front()<<endl;;//���ͷ�ڵ��Ԫ��,�൱��
	//list<int>::iterator ite3 = lst.begin();
	//cout<<(*ite3)<<endl;

	//cout<<lst.back()<<endl;
	//list<int>::iterator ite4 = lst.end();
	//--ite4;
	//cout<<(*ite4)<<endl;

	//list<int>::iterator ite5 = ::find(lst.begin(),lst.end(),3);//���ؽڵ�ĵ��������Ҳ�������end��
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
#include<iostream>
using namespace std;

struct Node
{
	int val;
	Node *pNext;
	Node(int v){
		val = v;
		pNext = NULL;
	}
};
//---------------------------1------------------------------
class CMyIterator{
public:
	Node *pTemp;
public:
	CMyIterator(){
		pTemp = NULL;
	}
	CMyIterator(Node*pH){
		pTemp = pH;
	}
public:
	bool operator == (Node* pNode){
		return pTemp == pNode?true:false;
	}
	bool operator != (Node* pNode){
		return pTemp != pNode?true:false;
	}
	Node* operator=(Node* pNode){
		pTemp = pNode;
		return pTemp;
	}
	int operator*(){
		if(pTemp){
			return pTemp->val;
		}
		return -1;
	}
	Node* operator++(){//左++
		pTemp = pTemp->pNext;
		return pTemp;
	}
	Node* operator++(int){//右++
		Node*pMark = pTemp;
		pTemp = pTemp->pNext;
		return pMark;
	}
};
//---------------------------1------------------------------
class MyList
{
public:
	Node *m_pHead;
	Node *m_pEnd;
	int m_nLen;
	MyList(){
		m_pHead = NULL;
		m_pEnd = NULL;
		m_nLen = 0;
	}
	~MyList(){//遍历链表，删除节点
		Node *pTemp = NULL;
		while (m_pHead)
		{
			pTemp = m_pHead;

			m_pHead = m_pHead->pNext;
			delete pTemp;
			pTemp = NULL;
		}
	}
public:
	void PushBack(int v){//尾添加
		Node *pTemp = new Node(v);
		if(m_pHead){
			m_pEnd->pNext = pTemp;
			m_pEnd = m_pEnd->pNext;
		}
		else
		{
			m_pHead = pTemp;
			m_pEnd = pTemp;
		}
		m_nLen++;
	}
	void Show(){//遍历
//----------------------------2-----------------------------
		//Node*pTemp = m_pHead;//原本
		//Node* pTemp = NULL;
		//pTemp = m_pHead;
		//while(pTemp){
		//	cout<<pTemp->val<<" ";
		//	pTemp = pTemp->pNext;
		//}
		//cout<<endl;
		//CMyIterator ite = m_pHead;//方法1
		//while(ite!=NULL){
		//	cout<<*ite<<" ";
		//	ite++;
		//}
		CMyIterator ite;//方法2
		ite = m_pHead;
		while(ite!=NULL){
			cout<<*ite<<" ";
			++ite;
		}
		cout<<endl;
	}
//----------------------------2-----------------------------
	void PopFront(){//删除节点  头删除
		if(m_pHead)
		{
			Node *pTemp = m_pHead;
			if(m_pHead == m_pEnd)
			{
				delete pTemp;
				pTemp = NULL;
				m_pHead =NULL;
				m_pEnd =NULL;
			}
			else
			{
				m_pHead = m_pHead->pNext;
				delete pTemp;
				pTemp =NULL;
			}

		}
		m_nLen--;
	}
};


int main()
{
	//Node node;
	//node.val=9;
	//cout<<node.val<<endl;

	MyList lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);
	lst.Show();



	system("pause");
	return 0;
}
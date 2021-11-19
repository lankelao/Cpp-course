#include<iostream>
using namespace std;
//����ṹ������
//���Ĭ�Ϸ������η���private,�ṹ���Ĭ�Ϸ������η���public
//���Ĭ�ϼ̳з�ʽ��private�����Ĭ�ϼ̳з�ʽ��public
struct Node
{
	int val;
	Node *pNext;
	Node(int v){
		val = v;
		pNext = NULL;
	}
};

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
	~MyList(){//��������ɾ���ڵ�
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
	void PushBack(int v){//β���
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
	void Show(){//����
		Node*pTemp = m_pHead;
		while(pTemp){
			cout<<pTemp->val<<" ";
			pTemp = pTemp->pNext;
		}
		cout<<endl;
	}
	void PopFront(){//ɾ���ڵ�  ͷɾ��
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

	lst.PopFront();
		lst.Show();
	lst.PopFront();
		lst.Show();
	lst.PopFront();
		lst.Show();
	lst.PopFront();
		lst.Show();
	lst.PopFront();
		lst.Show();

	system("pause");
	return 0;
}
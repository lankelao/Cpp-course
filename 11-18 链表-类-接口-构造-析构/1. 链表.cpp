#include<iostream>
using namespace std;


struct Node{		//��C++�в���typedef
	int val;
	Node *pNext;		//���ô�����struct
};

//void PushBack(Node * *pH,Node * *pE,int v){
//	Node *pNode = new Node;
//	pNode->val = v;
//	pNode->pNext = NULL;
//
//	if(*pH){
//		(*pE)->pNext = pNode;
//		(*pE) = pNode;
//	}
//	else{
//		(*pH) = pNode;
//		(*pE) = pNode;
//	}
//}
//---------------------��Ϊ����------------------------------
void PushBack(Node * &pH,Node * &pE,int v){
	Node *pNode = new Node;
	pNode->val = v;
	pNode->pNext = NULL;

	if(pH){
		(pE)->pNext = pNode;
		(pE) = pNode;
	}
	else{
		(pH) = pNode;
		(pE) = pNode;
	}
}
void show(Node* pH){
	//��������
	if(pH){
		while(pH){
			cout<< pH->val <<endl;
			pH = pH->pNext;
		}

	}
}


int main()
{
	Node *pHead = NULL;
	Node *pEnd = NULL;

	//PushBack(&pHead,&pEnd,1);
	//PushBack(&pHead,&pEnd,2);
	//PushBack(&pHead,&pEnd,3);
	//PushBack(&pHead,&pEnd,4);
//---------------------��Ϊ����------------------------------
	PushBack(pHead,pEnd,1);
	PushBack(pHead,pEnd,2);
	PushBack(pHead,pEnd,3);
	PushBack(pHead,pEnd,4);
	show(pHead);

system("pause");  
}

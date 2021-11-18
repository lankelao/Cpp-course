#include<iostream>
using namespace std;


struct Node{		//在C++中不用typedef
	int val;
	Node *pNext;		//不用带类型struct
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
//---------------------改为引用------------------------------
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
	//遍历链表
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
//---------------------改为引用------------------------------
	PushBack(pHead,pEnd,1);
	PushBack(pHead,pEnd,2);
	PushBack(pHead,pEnd,3);
	PushBack(pHead,pEnd,4);
	show(pHead);

system("pause");  
}

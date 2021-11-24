#include<iostream>
using namespace std;

class CFather{
public:
	CFather(){
		cout<<"fa"<<endl;
	}
	virtual~CFather(){     //虚析构
		cout<<"~fa"<<endl;
	}
};

class CSon:public CFather{
public:
	CSon(){
		cout<<"son"<<endl;
	}
	virtual~CSon(){
		cout<<"~son"<<endl;
	}
};

int main()
{
	CSon *pSon = new CSon;
	delete pSon;
	pSon = NULL;
//----------------------------------------------------------------------
	CFather *pSon1 = new CSon;
	delete (CSon*)pSon1;//这样不好，用虚析构
	pSon1 = NULL;
//----------------------------------------------------------------------
	CFather *pSon2 = new CSon;
	delete pSon2;
	pSon2 = NULL;

	system("pause");
	return 0;
}
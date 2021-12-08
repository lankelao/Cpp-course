#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

void show(int a){
	cout<< a <<"  ";
}

int main(){

	deque<int>de;
	de.push_back(3);
	de.push_back(6);
	de.push_back(2);
	de.push_back(5);
	de.push_back(9);
	//�±����
	for(int i=0;i<(int)de.size();i++){
		cout<< de[i] <<"  ";
	}
	cout<<endl;
	for(int val:de){
		cout<<val<<"  ";
	}
	cout<<endl;

	::for_each(de.begin(),de.end(),&show);cout<<endl;
	//ͷ���
	de.push_front(1);
	de.push_front(2);

	//����������
	deque<int>::iterator ite = de.begin();
	while(ite != de.end()){
		cout << *ite <<"  ";
		ite++;
		//ite+=2;
	}
	cout<<endl;
//==============================================================
	//list<int>lst;
	//lst.begin()+=2;//list��û������+=
	ite = de.begin();
	::advance(ite,de.size()-1);
	cout<<*ite<<endl;

	//vector<int>vec;
	//vec.begin()+=2;//vecter������+=
//=======================================================

	cout<<"-----------------------------------"<<endl;
	de.pop_back();
	::for_each(de.begin(),de.end(),&show);cout<<endl;
	de.pop_front();
	::for_each(de.begin(),de.end(),&show);cout<<endl;
	
	de.insert(++de.begin(),10);
	::for_each(de.begin(),de.end(),&show);cout<<endl;
	de.erase(++de.begin());
	::for_each(de.begin(),de.end(),&show);cout<<endl;
	
	cout<<"size = "<<de.size()<<endl;
	de.resize(de.size()+2);
	::for_each(de.begin(),de.end(),&show);cout<<endl;
	de.resize(de.size()-3);
	::for_each(de.begin(),de.end(),&show);cout<<endl;
	
	de.clear();
	::for_each(de.begin(),de.end(),&show);cout<<endl;
	cout<<"size = "<<de.size()<<endl;


	system("pause");
	return 0;
}
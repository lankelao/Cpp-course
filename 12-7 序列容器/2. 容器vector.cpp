#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;


void show(int a){
	cout<<a<<"  ";
}

int main(){
	//vector<int>vec;//��ʹ����size������ca����
	//cout<< vec.size()<<"  "<<vec.capacity()<<endl;//0  0

	vector<int>vec(2,4);//����Ԫ�ص�������������ʼ��ֵ
	cout<< vec.size()<<"  "<<vec.capacity()<<endl;//2  2
	vector<int>::iterator ite = vec.begin();
	while(ite!=vec.end()){
		cout<<*ite<<"  ";
		ite++;
	}
	cout<<endl;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<"  ";
	}
	cout<<endl;
	::for_each(vec.begin(),vec.end(),show);cout<<endl;
	cout<< vec.size()<<"  "<<vec.capacity()<<endl;

	//cout<<vec.front()<<endl;
	//cout<<vec.back()<<endl;

	//vec.pop_back();
	//::for_each(vec.begin(),vec.end(),show);cout<<endl;
	//cout<< vec.size()<<"  "<<vec.capacity()<<endl;
	//vec.pop_back();
	//::for_each(vec.begin(),vec.end(),show);cout<<endl;
	//cout<< vec.size()<<"  "<<vec.capacity()<<endl;

	//vec.insert(++vec.begin(),5);
	//::for_each(vec.begin(),vec.end(),show);cout<<endl;

	//vec.insert(++vec.begin(),2,5);
	//::for_each(vec.begin(),vec.end(),show);cout<<endl;

	//vec.erase(vec.begin());
	//::for_each(vec.begin(),vec.end(),show);cout<<endl;

	vector<int>::iterator ite1 = ++vec.begin();
	vec.erase(ite1);//����������������Ҫ��һ�£�vecɾ���˻���ָ��ԭ����
	::for_each(vec.begin(),vec.end(),show);cout<<endl;

	vec.clear();
	cout<< vec.size()<<"  "<<vec.capacity()<<endl;

	system("pause");
	return 0;
}
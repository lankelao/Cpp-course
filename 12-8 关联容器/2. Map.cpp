#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

void show(pair<string,int> pr){
	cout<<pr.first<<"  "<<pr.second<<endl;
}
int main(){

	map<string,int>mm;//键值，实值
	mm["DD"] = 100;
	mm["CC"] = 200;
	mm["UU"] = 300;
	mm["SS"] = 400;

	map<string,int>::iterator ite = mm.begin();
	while(ite != mm.end()){
		cout<<(*ite).first<<"  "<<(*ite).second<<endl;//根据键值排序
		ite++;
	}
	::for_each(mm.begin(),mm.end(),&show);

	cout<< mm["DD"] <<endl;//100
	cout<< mm["OO"] <<endl;//0内部是红黑树O(log2n)
	if(mm["OO"]){
		cout<<mm["OO"]<<endl;
	}else{
		cout<<"不存在"<<endl;
	}

	map<string,int>::iterator ite1 = mm.find("CC");
	cout<<ite1->first<<"  "<<ite1->second<<endl;

	pair<string,int> pr("II",20);
	mm.insert(pr);
	::for_each(mm.begin(),mm.end(),&show);

	cout<<"----------------------------------"<<endl;
	pair<string,int> pr2("PP",20);
	mm.insert(mm.begin(),pr2);
	::for_each(mm.begin(),mm.end(),&show);

	map<string,int>::iterator ite2 = mm.find("II");
	mm.erase(ite2);
	::for_each(mm.begin(),mm.end(),&show);

	cout<<"----------------------------------"<<endl;
	if(mm.count("PP")){
		cout<<mm["PP"]<<endl;
	}else{
		cout<<"不存在"<<endl;
	}

	cout<<mm.size()<<endl;

	cout<<"----------------------------------"<<endl;
	::for_each(mm.begin(),mm.end(),&show);
	map<string,int>::iterator ite3 = mm.lower_bound("PP");//大于等于PP的
	cout<<ite3->first<<"  "<<ite3->second<<endl;

	::for_each(mm.begin(),mm.end(),&show);
	map<string,int>::iterator ite31 = mm.lower_bound("QQ");
	cout<<ite31->first<<"  "<<ite31->second<<endl;

	cout<<"----------------------------------"<<endl;
	::for_each(mm.begin(),mm.end(),&show);
	map<string,int>::iterator ite4 = mm.upper_bound("PP");//大于PP的
	cout<<ite4->first<<"  "<<ite4->second<<endl;

	cout<<"----------------------------------"<<endl;
	ite4->second = 30000;
	::for_each(mm.begin(),mm.end(),&show);

	cout<<"----------------------------------"<<endl;
	mm["SS"] = 50000;
	::for_each(mm.begin(),mm.end(),&show);
	map<string,int>::iterator ite5 = mm.find("SS");
	//ite5->first = "MM";
	ite5->second = 60000;
	::for_each(mm.begin(),mm.end(),&show);

	system("pause");
	return 0;
}
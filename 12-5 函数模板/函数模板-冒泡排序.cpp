#include<iostream>
#include<typeinfo>
#include<algorithm>
#include<list>
using namespace std;

template<typename TT>
bool rule(TT a,TT b){
	return a < b;
}
bool rule1(int a,int b){
	return a > b;
}
bool rule2(double a,double b){
	return a < b;
}
template<typename TT>
void BubbleSort(TT *pArr,int length,bool(*p_fun)(TT,TT)){
	if(pArr==NULL || length<=0){
		return;
	}
	for(int i=0;i<length-1;i++){
		for(int j=0;j<length-1-i;j++){
			if((*p_fun)(pArr[j],pArr[j+1])/*pArr[j] > pArr[j+1]*/){
				TT temp = pArr[j];
				pArr[j] = pArr[j+1];
				pArr[j+1] = temp;
			}
		}
	}
}

void show(int a){
}

int main(){
	int arr[10] = {4,2,3,1,5,7,6,9,8,0};
	BubbleSort(arr,10,&rule1/*或者使用通用模板&rule<int>*/);
	for(int val:arr){
		cout<<val<<"  ";
	}
	cout<<endl;
	double arr1[10] = {4,2.3,3,1,5,7.7,6.6,9,8,0};
	BubbleSort(arr1,10,&rule2);
	for(double val:arr1){
		cout<<val<<"  ";
	}
	cout<<endl;


//--<int>和show(int a)的类型保持一致-----------------------
	list<int>lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	::for_each(lst.begin(),lst.end(),&show);

	system("pause");
	return 0;
}

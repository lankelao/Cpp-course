#include<iostream>
using namespace std;

//封装一个CDate类
//成员属性：年、月、日
//成员方法：构造、析构、显示日期(Display),设置日期(SetDate)...等
//一个CDate对象可以用三个整数表示年、月、日(如2021.11.11）来初始化，而且可以对日期的设置进行合法性校验，要求实现CDate类的成员
class CDate{
public:
	int m_nYear;
	int m_nMonth;
	int m_nDay;
public:
	CDate(){
		m_nYear = 1970;
		m_nMonth = 1;
		m_nDay = 1;
	}
	void SetDate(int year,int month,int day){
		if(1970<=year&&year<=2099){
			m_nYear = year;
		} 
		if(1<=month&&month<=12){
			m_nMonth = month;
		}
		if(1<=day&&day<=30){
			m_nDay = day;
		}
		
		return;
	}
	void Show()
	{
		cout<<m_nYear<<"-"<<m_nMonth<<"-"<<m_nDay<<endl;
	}

};


int main(){
	CDate date;
	date.Show();
	date.SetDate(2021,11,11);

	date.Show();

	system("pause");
	return 0;
}
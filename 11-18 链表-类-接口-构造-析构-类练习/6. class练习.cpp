#include<iostream>
using namespace std;

//��װһ��CDate��
//��Ա���ԣ��ꡢ�¡���
//��Ա���������졢��������ʾ����(Display),��������(SetDate)...��
//һ��CDate�������������������ʾ�ꡢ�¡���(��2021.11.11������ʼ�������ҿ��Զ����ڵ����ý��кϷ���У�飬Ҫ��ʵ��CDate��ĳ�Ա
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
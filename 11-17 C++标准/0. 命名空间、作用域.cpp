#include<iostream>
using namespace std;

int nAge = 10;
int main()
{
	int nAge = 20;
	cout << nAge << endl; 
//::�����������  ::ǰû�����ݴ���ȫ��
	cout << ::nAge <<endl; 
	//cout << std::nAge <<endl; Ҳ���Բ���using namespace std,ֱ����std::�������ռ�
	return 0;
}
//------------------------ʹ��������------------------------------
#include<iostream>
using namespace std;

namespace Bird
{
	int nAge = 10;
}
namespace Person
{
	int nAge = 20;
}
int main()
{
	cout << Person::nAge << endl; //��Person������
	return 0;
}

//----------------------------ʹ�������ռ�-------------------------------
#include<iostream>
using namespace std;

namespace Bird//����һ�������ռ�
{
	int nAge = 10;
}
namespace Person
{
	int nAge = 20;
}

using namespace Bird;  //��Bird�����ռ�Ҳ����
int main()
{
	cout << nAge << endl; 
	return 0;
}
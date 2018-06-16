#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPowOf2(int num);
int MChangeToN(int m, int n);
int main()
{

	cout << IsPowOf2(8) << endl;
	cout << MChangeToN(8, 4) << endl;
	system("pause");

	return 0;
}
//�ж�ĳ�����Ƿ���2��ָ���õ���
bool IsPowOf2(int num)
{
	unsigned int flag = 1;
	unsigned int count = 0;
	while (flag)
	{
		if (num & flag)
			++count;
		flag = flag << 1;
	}

	if (count == 1)
		return true;
	else
		return false;
}
//�ó����Ա�ʾM�Ķ�����ͨ���任����λ���Ա任Ϊ��ʾN��������
int MChangeToN(int m, int n)
{
	int num = m ^ n;
	unsigned int flag = 1;
	unsigned int count = 0;
	while (flag)
	{
		if (num & flag)
			++count;
		flag = flag << 1;
	}
	return count;
}
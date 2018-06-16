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
//判定某个数是否是2的指数得到的
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
//得出用以表示M的二进制通过变换多少位可以变换为表示N二进制数
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
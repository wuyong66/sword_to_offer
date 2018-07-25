#include <iostream>
#include <string>
#include <vector>

using namespace std;
void RecordOddEven_0(int *pData, unsigned int length);

void RecordOddEven(int *pData, unsigned int length);
int main()
{
	cout << "please input the length of your array: " << endl;
	int length = 0;
	cin >> length;
	int *array1 = new int[length];
	cout << "please input your array: " << endl;
	int tmp = 0;
	int cnt = 0;
	while (cin >> tmp && cnt <= length)    //ctrl + Z停止输入
	{
		array1[cnt] = tmp;
		++cnt;
	}

//	for (int i = 0; i < length; ++i)
//	{
//		int num = 0;
//		cin >> num;
//		array1[i] = num;
//	}
	RecordOddEven(array1, length);
	for (int i = 0; i < length; ++i)
	{
		cout << array1[i] << ends;
	}
	cout << '\n';
	system("pause");
	return 0;
}

void RecordOddEven(int *pData, unsigned int length)
{
	if (pData == NULL || length == 0)
		return;
	int *pBegin = pData;
	int *pEnd = pData + length - 1;

	while (pBegin < pEnd)                   //保证第一个指针在第二个指针前面
	{
		while (pBegin < pEnd && (*pBegin & 0x1 != 0))   //保证第一个指针指向的是偶数
			pBegin ++;
		while (pBegin < pEnd && (*pEnd & 0x1 == 0))     //保证第二个指针指向的是奇数
			pEnd --;
		if (pBegin < pEnd)                              //且满足大前提条件，则进行交换
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

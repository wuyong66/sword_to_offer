#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

bool  Increment(char * number);
void PrintNumber(char *number);
void Print1ToMaxOfNDigits(int n);


int main()
{
	int n = 0;
	cin >> n;
	Print1ToMaxOfNDigits(n);
	system("pause");

	return 0;
}

void Print1ToMaxOfNDigits(int n)
{
	if (n < 0)
		return;
	char *number = new char[n + 1];
	memset(number, '0', n);
	while (!Increment(number))
	{
		PrintNumber(number);
	}
	delete[] number;
}

// ====================方法一====================
void Print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
		return;

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}

	delete[]number;
}

// 字符串number表示一个数字，在 number上增加1
// 如果做加法溢出，则返回true；否则为false
bool Increment(char* number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
			nSum++;

		if (nSum >= 10)
		{
			if (i == 0)
				isOverflow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}

	return isOverflow;
}

// ====================公共函数====================
// 字符串number表示一个数字，数字有若干个0开头
// 打印出这个数字，并忽略开头的0
void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; ++i)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;

		if (!isBeginning0)
		{
			printf("%c", number[i]);
		}
	}

	printf("\t");
}
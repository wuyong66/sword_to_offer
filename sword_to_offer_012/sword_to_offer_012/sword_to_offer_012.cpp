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

// ====================����һ====================
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

// �ַ���number��ʾһ�����֣��� number������1
// ������ӷ�������򷵻�true������Ϊfalse
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

// ====================��������====================
// �ַ���number��ʾһ�����֣����������ɸ�0��ͷ
// ��ӡ��������֣������Կ�ͷ��0
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
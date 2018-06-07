#include <iostream>
#include <string>

using namespace std;

#define ERROR 0
#define OK 1
#define MAXSIZE 100

int RepalceBlank(char string[], int length);

int main()
{	
	cout << "please input your string:" << endl;
	char str[MAXSIZE];
	cin.get(str, MAXSIZE);
	if (RepalceBlank(str, MAXSIZE))
	{
		cout << '\n';
		cout << "string after replacing: " << str;
		return OK;
	}
	else
		return ERROR;

}
/*
* Summary: replace blank by "20%"
*Parameters:
	* string: 字符数组，存放字符的数组
	* length: 字符数组最大可容纳的大小
* return void
*/
int RepalceBlank(char string[], int length)
{
	if (string == NULL || length <= 0)
		return ERROR;
	int originalLength = 0;  //原来字符串的大小
	int numberOfBlank = 0;  //原来字符串中空格的数量
	int i = 0;
	while (string[i] != '\0')
	{
		++i;
		if (string[i] == ' ')
			++numberOfBlank;
	}
	originalLength = i;
	
	int newLength = originalLength + 2 * numberOfBlank;   //替换之后字符串的总长度
	if (newLength >= length)
		return ERROR;

	int indexOfOriginal = originalLength;   //索引号，指向未移动素组最后一个元素
	int indexOfNew = newLength;   //指向移动后的数组第一个元素

	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';	
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		indexOfOriginal--;  //怎么样都需要前移一位
	}
	return OK;
}
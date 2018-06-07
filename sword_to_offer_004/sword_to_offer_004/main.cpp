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
	* string: �ַ����飬����ַ�������
	* length: �ַ������������ɵĴ�С
* return void
*/
int RepalceBlank(char string[], int length)
{
	if (string == NULL || length <= 0)
		return ERROR;
	int originalLength = 0;  //ԭ���ַ����Ĵ�С
	int numberOfBlank = 0;  //ԭ���ַ����пո������
	int i = 0;
	while (string[i] != '\0')
	{
		++i;
		if (string[i] == ' ')
			++numberOfBlank;
	}
	originalLength = i;
	
	int newLength = originalLength + 2 * numberOfBlank;   //�滻֮���ַ������ܳ���
	if (newLength >= length)
		return ERROR;

	int indexOfOriginal = originalLength;   //�����ţ�ָ��δ�ƶ��������һ��Ԫ��
	int indexOfNew = newLength;   //ָ���ƶ���������һ��Ԫ��

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
		indexOfOriginal--;  //��ô������Ҫǰ��һλ
	}
	return OK;
}
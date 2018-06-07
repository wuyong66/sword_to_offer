#include <iostream>
#include <string>
#include <exception>

using namespace std;

#define MAXSIZE 100
//旋转数组之我解，哈哈哈哈哈哈
int Min_v0(int array[], int length);
int Min_v1(int array[], int length);

int main()
{
	cout << "please input the array:\n" << endl;
	int arr[MAXSIZE];
	int tmp = 0;
	int i = 0;
	while (cin >> tmp)
	{
		arr[i++] = tmp;

	}
	int length = i;
	int min = Min_v1(arr, length);
	cout << "min = " << min << endl;
	system("pause");
	
	return 0;

}

int Min_v0(int array[], int length)
{
	if (array == NULL || length <= 0)
		throw std::exception("Invalid parameters");
	int min = array[0];
	for (int i = 0; i < length; ++i)
	{
		if (min > array[i])
			min = array[i];
	}
	return min;
}

int Min_v1(int array[], int length)
{
	if (array == NULL || length <= 0)
		throw new std::exception("Invalid parameters");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (array[index1] >= array[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if (array[indexMid] >= array[index1])
			index1 = indexMid;
		else if (array[indexMid] <= array[index2])
			index2 = indexMid;
	}
	return array[index2];
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXSIZE 100

void printArray(int arr[], int size);
void MergeArr(int arr1[], int arr2[], int size_1, int size_2);//输入A和B的数组和两个长度 

int main()
{
	int array1[MAXSIZE], array2[MAXSIZE];
	int size_1 = 0, size_2 = 0;
	printf("please input the members of array1: \n");
	int *ptr1 = array1;
	while (scanf_s("%d", ptr1++, 1))
	{
		size_1++;    //是大小而不是下标， 所以要大1
		if (getchar() == '\n')
			break;
	}

	printf("\n");
	printArray(array1, size_1);
	printf("\n");

	printf("please input the members of array2: \n");
	int *ptr2 = array2;
	while (scanf_s("%d", ptr2++, 1))
	{
		size_2++;  //是大小而不是下标， 所以要大1
		if (getchar() == '\n')
			break;

	}
	printf("\n");
	printArray(array2, size_2);

	printf("\n合并之后的数组为：\n");
	MergeArr(array1, array2, size_1, size_2);
	printArray(array1, size_1 + size_2);
	printf("\n");

	system("pause");
	return 0;
}


/*
* Summary: 打印数组内的元素
*Parameters:
	* arr:    数组名
	* size:   数组大小
* return void
*/
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
}

/*
* Summary: 合并两个有序的数组，使之仍然有序
*Parameters:
	* arr1:    数组1
	* arr2:    数组2
	* size_1:  数组1的大小
	* size_2:  数组2的大小
* return void
*/
void MergeArr(int arr1[], int arr2[], int size_1, int size_2)      //输入A和B的数组和两个长度  
{
	if (size_1 <= 0 || size_2 <= 0)
		return;

	int index_of_all = size_1 + size_2 - 1;   //总的数组长度
	int index_of_1 = size_1 - 1;      //数组1的游标    
	int index_of_2 = size_2 - 1;      //数组2的游标

	while (index_of_all >= 0)
	{
		if (arr1[index_of_1] > arr2[index_of_2] || index_of_2 < 0)        //注意边界条件，当数组1中没有元素时，也要移动  
			arr1[index_of_all--] = arr1[index_of_1--];
		else if (arr1[index_of_1] <= arr2[index_of_2] || index_of_1 < 0)  //注意边界条件，当数组2中没有元素时，也要移动  
			arr1[index_of_all--] = arr2[index_of_2--];
	}
}


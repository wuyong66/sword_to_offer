#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXSIZE 100

void printArray(int arr[], int size);
void MergeArr(int arr1[], int arr2[], int size_1, int size_2);//����A��B��������������� 

int main()
{
	int array1[MAXSIZE], array2[MAXSIZE];
	int size_1 = 0, size_2 = 0;
	printf("please input the members of array1: \n");
	int *ptr1 = array1;
	while (scanf_s("%d", ptr1++, 1))
	{
		size_1++;    //�Ǵ�С�������±꣬ ����Ҫ��1
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
		size_2++;  //�Ǵ�С�������±꣬ ����Ҫ��1
		if (getchar() == '\n')
			break;

	}
	printf("\n");
	printArray(array2, size_2);

	printf("\n�ϲ�֮�������Ϊ��\n");
	MergeArr(array1, array2, size_1, size_2);
	printArray(array1, size_1 + size_2);
	printf("\n");

	system("pause");
	return 0;
}


/*
* Summary: ��ӡ�����ڵ�Ԫ��
*Parameters:
	* arr:    ������
	* size:   �����С
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
* Summary: �ϲ�������������飬ʹ֮��Ȼ����
*Parameters:
	* arr1:    ����1
	* arr2:    ����2
	* size_1:  ����1�Ĵ�С
	* size_2:  ����2�Ĵ�С
* return void
*/
void MergeArr(int arr1[], int arr2[], int size_1, int size_2)      //����A��B���������������  
{
	if (size_1 <= 0 || size_2 <= 0)
		return;

	int index_of_all = size_1 + size_2 - 1;   //�ܵ����鳤��
	int index_of_1 = size_1 - 1;      //����1���α�    
	int index_of_2 = size_2 - 1;      //����2���α�

	while (index_of_all >= 0)
	{
		if (arr1[index_of_1] > arr2[index_of_2] || index_of_2 < 0)        //ע��߽�������������1��û��Ԫ��ʱ��ҲҪ�ƶ�  
			arr1[index_of_all--] = arr1[index_of_1--];
		else if (arr1[index_of_1] <= arr2[index_of_2] || index_of_1 < 0)  //ע��߽�������������2��û��Ԫ��ʱ��ҲҪ�ƶ�  
			arr1[index_of_all--] = arr2[index_of_2--];
	}
}


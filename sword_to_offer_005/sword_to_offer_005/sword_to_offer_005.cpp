#include <iostream>
#include <string>
#include <vector>
#include <stack>   
#include <stdlib.h>
#include <time.h>

using namespace std;

//������ṹ, �Ժ�ֻҪ�ǹ���������⣬��Ĭ��û��ͷ���
typedef struct ListNode
{
	int data;
	struct ListNode *next;
}ListNode, *LinkList;   

/*
--Summary: ����������ӡ�����е�����
--Parameter: 
----L:�������ͷָ��
Return: void
*/
void PrintList(LinkList L)
{
	if (!L)
		return;
	LinkList pHead = L;
	while (pHead)
	{
		cout << pHead->data << ends;
		pHead = pHead->next;
	}
	cout << '\n';
	return;
}
/*
--Summary: ����ͷ�巨����ʹ�����������ʼ��һ������
--Parameter: 
----pL������Ҫ�Կ��ܻ�������ͷ���в��������������ͷָ����ܻᷢ���仯�����Բ�����Ҫָ��ָ���ָ��ſ��ԣ�
----size: ��ʾ��ʼ������ĳ���
Return��void
*/
void CreatListHead(LinkList *pL, const int size)
{
	/*
	if (size < 1)
		return;
	srand((unsigned)time(NULL));   //�������������
	for (int i = 0; i < size; ++i)
	{
		int tmp = rand() % 100 + 1;
		LinkList pHead = new ListNode();
		pHead->data = tmp;
		pHead->next = *pL;
		(*pL) = pHead;
	}
	return;	
	*/
	if (size < 1)
		return;
	srand((unsigned)time(NULL));   //�������������

	(*pL) = new ListNode();     //����ͷָ�룬ͷ���
	(*pL)->data = rand() % 100 + 1;
	(*pL)->next = nullptr;

	for (int i = 0; i < size - 1; ++i)
	{
		LinkList pHead = new ListNode();
		pHead->data = rand() % 100 + 1;
		pHead->next = (*pL)->next;
		(*pL)->next = pHead;
	}

}

/*
--Summary: ����β�巨����ʹ�����������ʼ��һ������
--Parameter:
----pL������Ҫ�Կ��ܻ�������ͷ���в��������������ͷָ����ܻᷢ���仯�����Բ�����Ҫָ��ָ���ָ��ſ��ԣ�
----size: ��ʾ��ʼ������ĳ���
Return��void
*/
void CreatListTail(LinkList *pL, const int size)
{
	if (size < 1) //������һ������ִ�����²���
		return;
	srand((unsigned)time(NULL));   //�������������

	(*pL) = new ListNode();     //����ͷָ�룬ͷ���
	(*pL)->data = rand() % 100 + 1;
	(*pL)->next = nullptr;

	//֮���Բ��� LinkList *p = pL;
	//pL���˫��ָ�룬ֻ��Ϊ��������ͷ��㣨��ַ�������ı�ʱ���ܹ��ѵ�ַ�����ͳ�ȥ
	//���ֻ�в����漰�����ܸı�ͷ���ʱ���Ż���ָ��ָ���ָ�룬
	LinkList p = *pL;   // ʵ���ϲ�������ͬһ���ڴ�

	for (int i = 0; i < size - 1; ++i)
	{
		int tmp = rand() % 100 + 1;
		LinkList pHead = new ListNode();
		pHead->data = tmp;
		pHead->next = nullptr;

		p->next = pHead;
		p = pHead;

	}
	return;
}

/*
--Summary: ʹ��C++��׼�����stack��ջ���ṹ�����������Ԫ��
--Parameters:
----L: �����ͷָ��
--Return: void
*/
void PrintListReversingly_Iteratively(LinkList L)
{
	stack<LinkList> nodes;
	LinkList pHead = L;
	while (pHead)
	{
		nodes.push(pHead);
		pHead = pHead->next;
	}
	while (!nodes.empty())
	{
		cout << (nodes.top())->data << ends;
		nodes.pop();
	}
	cout << "\n";
	return;
}

/*
--Summary: ��Ȼ������ջ�ṹ��ʵ�ֵ����������ôҲ����ʹ�õݹ���ʵ�ֵ������
--Parameter:
----L�������ͷָ��
--Return��void
*/
void PrintListReversingly_Recursively(LinkList L)
{
	if (L)
	{
		PrintListReversingly_Recursively(L->next);
		cout << L->data << ends;
	}
}


/*
--Summary: ָ�뷴����е��������������ı�ԭ������Ľṹ
--Parameter:
----pL������Ҫ�Կ��ܻ�������ͷ���в��������������ͷָ����ܻᷢ���仯�����Բ�����Ҫָ��ָ���ָ��ſ��ԣ�
--Return��void
*/
void PrintListReversingly_or_ptr(LinkList *pL)
{
	LinkList pre = NULL;
	LinkList head = (*pL);
	LinkList next;

	while (head)
	{
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;	
	}
	(*pL) = pre;
}



int main()
{
	LinkList L = nullptr;
	CreatListHead(&L, 10);
	PrintList(L);
	PrintListReversingly_Recursively(L);
	cout << '\n';
	PrintListReversingly_Iteratively(L);
	PrintListReversingly_or_ptr(&L);
	PrintList(L);
	system("pause");
	return 0;                  
}
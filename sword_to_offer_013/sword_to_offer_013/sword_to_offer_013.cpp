#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <stdio.h>
#include <time.h>

using namespace std;

typedef struct ListNode
{
	int  m_nValue;
	struct ListNode * m_pNext;
}ListNode, *LinkList;

void DeleteNode(ListNode ** pListHead, ListNode * pToBeDeleted);     //以复杂度为O（1）的时间复杂度；
void CreatListTail(LinkList *pL, const int size);
void CreatListHead(LinkList *pL, const int size);
void PrintList(LinkList L);

int main()
{
	LinkList L = nullptr;
	CreatListHead(&L, 10);
	PrintList(L);
	auto pListNode1 = L->m_pNext->m_pNext->m_pNext;
	DeleteNode(&L, pListNode1);
	printf("删除之后链表的内容为：\n");
	PrintList(L);
	system("pause");
	
	return  0;
}
/*
	summary: 以复杂度为O(1)的时间复杂度；
	parameter: 
		pListHead : 待闪出1链表的头结点；
		pToBeDeleted : 指向待删除结点的指针；
	return: void 
*/
void DeleteNode(LinkList* pListHead, ListNode* pToBeDeleted)    
{
	if (!pListHead || !pToBeDeleted)
		return;
	if (pToBeDeleted->m_pNext != NULL)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = NULL;
	}
	else if (*pListHead == pToBeDeleted)    //只有一个头结点，删除头结点
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else
	{
		ListNode * pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}
/*
--Summary: 采用头插法，并使用随机数来初始化一个链表；
--Parameter:
----pL：由于要对可能会对链表的头进行操作，所以链表的头指针可能会发生变化，所以参数需要指向指针的指针才可以；
----size: 表示初始化链表的长度
Return：void
*/
void CreatListHead(LinkList *pL, const int size)
{
	/*
	if (size < 1)
	return;
	srand((unsigned)time(NULL));   //设置随机数种子
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
	srand((unsigned)time(NULL));   //设置随机数种子
	(*pL) = new ListNode();     //产生头指针，头结点
	(*pL)->m_nValue = rand() % 100 + 1;
	(*pL)->m_pNext = nullptr;

	for (int i = 0; i < size - 1; ++i)
	{
		LinkList pHead = new ListNode();
		pHead->m_nValue = rand() % 100 + 1;
		pHead->m_pNext = (*pL)->m_pNext;
		(*pL)->m_pNext = pHead;
	}

}

/*
--Summary: 采用尾插法，并使用随机数来初始化一个链表；
--Parameter:
----pL：由于要对可能会对链表的头进行操作，所以链表的头指针可能会发生变化，所以参数需要指向指针的指针才可以；
----size: 表示初始化链表的长度
Return：void
*/
void CreatListTail(LinkList *pL, const int size)
{
	if (size < 1) //至少有一个结点才执行以下操作
		return;
	srand((unsigned)time(NULL));   //设置随机数种子

	(*pL) = new ListNode();     //产生头指针，头结点
	(*pL)->m_nValue = rand() % 100 + 1;
	(*pL)->m_pNext = nullptr;

	//之所以不是 LinkList *p = pL;
	//pL这个双重指针，只是为了在链表头结点（地址）发生改变时，能够把地址给传送出去
	//因此只有操作涉及到可能改变头结点时，才会用指向指针的指针，
	LinkList p = *pL;   // 实际上操作的是同一块内存

	for (int i = 0; i < size - 1; ++i)
	{
		int tmp = rand() % 100 + 1;
		LinkList pHead = new ListNode();
		pHead->m_nValue = tmp;
		pHead->m_pNext = nullptr;

		p->m_pNext = pHead;
		p = pHead;

	}
	return;
}

/*
--Summary: 遍历链表，打印链表中的数据
--Parameter:
----L:是链表的头指针
Return: void
*/
void PrintList(LinkList L)
{
	if (!L)
		return;
	LinkList pHead = L;
	while (pHead)
	{
		cout << pHead->m_nValue << ends;
		pHead = pHead->m_pNext;
	}
	cout << '\n';
	return;
}

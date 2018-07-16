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

void DeleteNode(ListNode ** pListHead, ListNode * pToBeDeleted);     //�Ը��Ӷ�ΪO��1����ʱ�临�Ӷȣ�
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
	printf("ɾ��֮�����������Ϊ��\n");
	PrintList(L);
	system("pause");
	
	return  0;
}
/*
	summary: �Ը��Ӷ�ΪO(1)��ʱ�临�Ӷȣ�
	parameter: 
		pListHead : ������1�����ͷ��㣻
		pToBeDeleted : ָ���ɾ������ָ�룻
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
	else if (*pListHead == pToBeDeleted)    //ֻ��һ��ͷ��㣬ɾ��ͷ���
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
	(*pL)->m_nValue = rand() % 100 + 1;
	(*pL)->m_pNext = nullptr;

	//֮���Բ��� LinkList *p = pL;
	//pL���˫��ָ�룬ֻ��Ϊ��������ͷ��㣨��ַ�������ı�ʱ���ܹ��ѵ�ַ�����ͳ�ȥ
	//���ֻ�в����漰�����ܸı�ͷ���ʱ���Ż���ָ��ָ���ָ�룬
	LinkList p = *pL;   // ʵ���ϲ�������ͬһ���ڴ�

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
		cout << pHead->m_nValue << ends;
		pHead = pHead->m_pNext;
	}
	cout << '\n';
	return;
}

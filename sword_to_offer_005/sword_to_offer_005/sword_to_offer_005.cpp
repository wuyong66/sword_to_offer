#include <iostream>
#include <string>
#include <vector>
#include <stack>   
#include <stdlib.h>
#include <time.h>

using namespace std;

//定义结点结构, 以后只要是关于链表的题，都默认没有头结点
typedef struct ListNode
{
	int data;
	struct ListNode *next;
}ListNode, *LinkList;   

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
		cout << pHead->data << ends;
		pHead = pHead->next;
	}
	cout << '\n';
	return;
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
	(*pL)->data = rand() % 100 + 1;
	(*pL)->next = nullptr;

	//之所以不是 LinkList *p = pL;
	//pL这个双重指针，只是为了在链表头结点（地址）发生改变时，能够把地址给传送出去
	//因此只有操作涉及到可能改变头结点时，才会用指向指针的指针，
	LinkList p = *pL;   // 实际上操作的是同一块内存

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
--Summary: 使用C++标准库里的stack（栈）结构，来倒序输出元素
--Parameters:
----L: 链表的头指针
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
--Summary: 既然可以用栈结构来实现倒序输出，那么也可以使用递归来实现倒序输出
--Parameter:
----L：链表的头指针
--Return：void
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
--Summary: 指针反向进行倒序输出，这样会改变原有链表的结构
--Parameter:
----pL：由于要对可能会对链表的头进行操作，所以链表的头指针可能会发生变化，所以参数需要指向指针的指针才可以；
--Return：void
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
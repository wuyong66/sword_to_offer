#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

//创建一个结点
BiTree CreateBiTreeNode(int data)
{
	BiTree pNode = new BiTreeNode();
	pNode->data = data;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	return pNode;
}

void ConnectBiTreeNodes(BiTree pParent, BiTree pLeft, BiTree pRight)
{
	if (pParent != nullptr)
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

void PrintBiTreeNode(BiTree pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is :%d \n", pNode->data);
		if (pNode->m_pLeft != nullptr)
			printf("value of its left child is : %s \n", pNode->m_pLeft->data);
		else
			printf("left child is NULL\n");
		if (pNode->m_pRight != nullptr)
			printf("value of its right child is: %s \n", pNode->m_pRight->data);
		else
			printf("right child is NULL\n");
	}
	else
		printf("this node is NULL\n");
	printf("\n");
}

void PrintBiTree(BiTree pRoot)
{
	PrintBiTreeNode(pRoot);
	if (pRoot != nullptr)
	{
		if (pRoot->m_pLeft != nullptr)
			PrintBiTree(pRoot->m_pLeft);
		if (pRoot->m_pRight != nullptr)
			PrintBiTree(pRoot->m_pRight);
	}
}

void Destory(BiTree pRoot)
{
	if (pRoot != nullptr)
	{
		BiTree pLeft = pRoot->m_pLeft;
		BiTree pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		Destory(pLeft);
		Destory(pRight);
	}
}






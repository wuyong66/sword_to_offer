#ifndef _BiTree_H
#define _BiTree_H


typedef struct BiTreeNode
{
	int data;
	struct BiTreeNode* m_pLeft;
	struct BiTreeNode* m_pRight;
}BiTreeNode, *BiTree;



BiTree CreateBiTreeNode(int data);
void ConnectBiTreeNodes(BiTree pParent, BiTree  pLeft, BiTree pRight);
void PrintBiTreeNode(BiTree pNode);
void PrintBiTree(BiTree pRoot);
void Destory(BiTreeNode *pRoot);


#endif

#include <iostream>
#include <exception>
#include "BiTree.h"

using namespace std;

BiTree ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder);
BiTree Construct(int* preorder, int* inorder, int length);

/*
--Summary: ���õݹ�ķ�����ͨ��ǰ���������������ع��������ĺ��ģ��ݹ����
--Parameter:
----startPreorder: ָ��ǰ��������е�һ��Ԫ��
----endPreorder:   ָ��ǰ������������һ��Ԫ��
----startInorder:  ָ������������е�һ��Ԫ��
----endInorder:    ָ����������������һ��Ԫ��
--Return: BiTree�� ���ص��Ǹ����
*/
BiTree ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
	int rootValue = startPreorder[0];
	BiTree root = new BiTreeNode();
	root->data = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
		{
			return root;
		}
		else
		{
			throw std::exception("Invalid input. ");
		}
	}
	//������������ҵ�������ֵ
	int *rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;

	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input.");

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		// ����������
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
			startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		// ����������
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
			rootInorder + 1, endInorder);
	}
	return root;

}

/*
--Summary: ���õݹ�ķ�����ͨ��ǰ���������������ع����������ǵ��ú��ĵģ���Ҫ��������⺯���Ĵ������
--Parameter:
----preorder: ǰ���������
----inorder:  ��Ѯ��������
----length :  �����еĳ���
--Return: BiTree�� ���ص��Ǹ����
*/
BiTree Construct(int* preorder, int* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;

	return ConstructCore(preorder, preorder + length - 1,
		inorder, inorder + length - 1);
}


// ====================���Դ���====================
void Test(char* testName, int* preorder, int* inorder, int length)
{
	if (testName != NULL)
		printf("%s begins:\n", testName);

	printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", preorder[i]);
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", inorder[i]);
	printf("\n");

	try
	{
		BiTree root = Construct(preorder, inorder, length);
		PrintBiTree(root);
		cout << "ao" << endl;
		Destory(root);

	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}

// ��ͨ������
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
	const int length = 8;
	int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Test("Test1", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 5, 4, 3, 2, 1 };

	Test("Test2", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 1, 2, 3, 4, 5 };

	Test("Test3", preorder, inorder, length);
}

// ����ֻ��һ�����
void Test4()
{
	const int length = 1;
	int preorder[length] = { 1 };
	int inorder[length] = { 1 };

	Test("Test4", preorder, inorder, length);
}

// ��ȫ������
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };

	Test("Test5", preorder, inorder, length);
}

// �����ָ��
void Test6()
{
	Test("Test6", NULL, NULL, 0);
}

// ������������в�ƥ��
void Test7()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 8, 1, 6, 3, 7 };

	Test("Test7: for unmatched input", preorder, inorder, length);
}


int main()
{
	Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	system("pause");

	return 0;
}

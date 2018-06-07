#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

template <typename T>
class CQueue
{
public:
	CQueue(void){};
	~CQueue(void){};
	void appendTail(const T &node);
	T deleteHead();

private:
	stack<T >stack1;
	stack<T >stack2;
};

template<typename T> 
void CQueue<T>::appendTail(const T &node)
{
	stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.size() == 0)
		throw new exception("queue is empty");
	T head = stack2.top();
	stack2.pop();

//这一段可以不加，加了增加了复杂度，不加不便于理解
	/*
	while (stack2.size() > 0)
	{
		T data = stack2.top();
		stack2.pop();
		stack1.push(data);
	}	
	*/


	return head;
}

/************************************************
		队1尾	\             /  队2头
				 \           /
				  \         /
				   \       /
					\     /   
			   队1头 \   / 队2尾
    stack1           栈顶          stack2
*************************************************/

void Test(char actual, char expected)
{
	if (actual == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main()
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test(head, 'a');

	head = queue.deleteHead();
	Test(head, 'b');

	queue.appendTail('d');
	head = queue.deleteHead();
	Test(head, 'c');

	queue.appendTail('e');
	head = queue.deleteHead();
	Test(head, 'd');

	head = queue.deleteHead();
	Test(head, 'e');

	system("pause");
	return 0;
}
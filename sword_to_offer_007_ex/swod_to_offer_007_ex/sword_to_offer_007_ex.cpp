#include <iostream>
#include <string>
#include <queue>
#include <exception>

using namespace std;

//队列数据结构的类模板
template<typename T> class CStack
{
public:
	CStack(void){};
	~CStack(void){};

	void appendTail(const T &node);      //队尾入队列
	T deleteHead();                      //队头出队列
private:
	queue<int> queue1;
	queue<int> queue2;

};

template<typename T> void CStack<T>::appendTail(const T &node)
{
	//TODO
	if (queue1.size() >= 0)
	{
		if (queue2.size() == 0)
		{
			queue1.push(node);
		}
	}
	if (queue2.size() >= 0)
	{
		if (queue1.size() == 0)
		{
			queue2.push(node);
		}
	}

}

template<typename T> T CStack<T>::deleteHead()
{
	//TODO
	T node;
	if (queue1.size() == 0 && queue2.size() == 0)
		throw new exception("stack is empty");
	if (queue1.size() > 0)
	{
		if (queue2.size() == 0)
		{
			while (queue1.size() > 1)
			{
				T tmp = queue1.front();
				queue1.pop();
				queue2.push(tmp);
			}
			node = queue1.front();
			queue1.pop();
			return node;
		}
	}
	if (queue2.size() > 0)
	{
		if (queue1.size() == 0)
		{
			while (queue2.size() > 1)
			{
				T tmp = queue2.front();
				queue2.pop();
				queue1.push(tmp);
			}
			node = queue2.front();
			queue2.pop();
			return node;
		}
	}
}
int main() 
{
	CStack<int > mystack;
	for (int i = 0; i < 5; ++i)
		mystack.appendTail(i);
	int tmp1 = mystack.deleteHead();
	int tmp2 = mystack.deleteHead();
	cout << tmp1 << ends << tmp2 << endl;
	mystack.appendTail(9);
	int tmp3 = mystack.deleteHead();
	cout << tmp3 << endl;
	system("pause");
	
	return 0;
}
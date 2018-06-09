#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long Fibonacci_v0(unsigned int n);
long long Fibonacci_v1(unsigned int n);
int main()
{
	cout << Fibonacci_v1(10);
	system("pause");
	return 0;
}
//递归的解法
long long Fibonacci_v0(unsigned int n)
{
	if (n <= 1)
		return n > 0 ? 1 : 0;
	else
		return Fibonacci_v0(n - 1) + Fibonacci_v0(n - 2);
}

//迭代的解法 
long long Fibonacci_v1(unsigned int n)
{
	if (n <= 1)
		return n > 0 ? 1 : 0;
	else
	{
		int FibonacciOne = 0;
		int FibonacciTwo = 1;
		int FibonacciN = 0;
		for (unsigned int i = 2; i <= n; ++i)
		{
			FibonacciN = FibonacciOne + FibonacciTwo;
			FibonacciOne = FibonacciTwo;
			FibonacciTwo = FibonacciN;
		}
		return FibonacciN;
	}
}

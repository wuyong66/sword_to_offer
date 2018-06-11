#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

unsigned int fun(unsigned int);
int main()
{
	cout << "please input the number of floor: ";
	
	int floor = 0;
	cin >> floor;
	if (floor <= 0)
	{		
		return -1;
	}

	cout << "the number of method is : " << fun(floor) << endl;
	system("pause");
	return 0;
}


unsigned int fun(unsigned int floor)
{
	if (floor <= 2)
		return floor > 1 ? 2 : 1;
	else
		return fun(floor - 1) + fun(floor - 2);
}
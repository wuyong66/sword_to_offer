#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;


unsigned int count_num_of_one_1(int number);
unsigned int count_num_of_one_2(int number);

int main()
{
	
	int number = 0;
	cin >> number;
	cout << '\n' << count_num_of_one_2(number) << endl;


	system("pause");
	return 0;
}


unsigned int count_num_of_one_1(int number)
{
	if (number >= 0)
	{
		bitset<32>bitVec(number);
		return bitVec.count();
	}

	else
	{
		bitset<32>bitVec(-number);
		return bitVec.count() + 1;
	}
}

unsigned int count_num_of_one_2(int number)
{
	int n = 0;
	unsigned int num = 1;
	while (num)
	{
		if (number & num)
		{
			++n;
		}
		num = num << 1;
	}
	return n;
}


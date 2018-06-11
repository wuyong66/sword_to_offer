#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

unsigned int count_num_of_one(int number);
int main()
{
	
	int number = 0;
	cin >> number;
	if (number < 0)
		return -1;
	cout << '\n' << count_num_of_one(number) << endl;

	//////////////////////////////////
	int tmp = 0xffffffff;
	cout << tmp;
	system("pause");
	return 0;
}


unsigned int count_num_of_one(int number)
{
	bitset<32>bitVec(number);
	return bitVec.count();
}
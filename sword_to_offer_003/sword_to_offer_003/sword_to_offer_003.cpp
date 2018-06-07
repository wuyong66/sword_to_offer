#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Find(int **matrix, int rows, int columns, int number, int *x, int *y);

int main()
{
	int M = 0, N = 0;
	cout << "input M and N:";
	cin >> M >> N;
	int **p2dArray = new int*[M];
	cout << "input M * N numbers:" << endl;
	for (int i = 0; i < M; ++i)
	{
		p2dArray[i] = new int[N];
	}
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> p2dArray[i][j];
		}
	}
	cout << "the matrix is:" << endl;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << p2dArray[i][j] << ends;
		}
		cout << '\n';
	}

	int x = 0;
	int y = 0;

	if (Find(p2dArray, M, N, 7, &x, &y))
		cout << "row: " << x << '\n' << "column: " << y << endl;
	else
		cout << "there is not " << endl;


	for (int i = 0; i < M; ++i)   //nothing
		delete[] p2dArray[i];

	return 0;
}


bool Find(int **matrix, int rows, int columns, int number, int *x, int *y)
{
	bool found = false;
	if (matrix != NULL && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0)
		{
			if (matrix[row][column] == number)
			{
				found = true;
				*x = row + 1;
				*y = column + 1;
				break;
			}
			else if (matrix[row][column] > number)
			{
				--column;
			}
			else
			{
				++row;
			}
		}
	}
	return found;
}

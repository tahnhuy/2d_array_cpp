#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void input(int a[20][20], int &rows, int &cols)
{
	cout << "Enter numbers of rows: ";
	cin >> rows;
	cout << "Enter numbers of columns: ";
	cin >> cols;
	
	srand(time(0));
	for (int i = 0; i < rows; ++i) 
	{
		for (int j = 0; j < cols; ++j)
		{
			a[i][j] = rand() % 50 + 1;
		}
	}
}

void print(int a[20][20], int rows, int cols)
{
	for (int i = 0; i < rows; ++i) 
	{
		for (int j = 0; j < cols; ++j)
		{
			cout << setw(3) << a[i][j];
		}
		cout << endl;
	}
	
	cout << endl;
}

void changeRows(int a[20][20], int rows, int cols)
{
	for (int k = 0; k < rows; ++k)
	{
		for (int i = 0; i < cols - 1; ++i)
		{
			for (int j = 0; j < cols - i - 1; ++j)
			{
				if (a[k][j] > a[k][j + 1])
				{
					int temp = a[k][j];
					a[k][j] = a[k][j + 1];
					a[k][j + 1] = temp;
				}
			}
		}
	}
}

void changeCols(int a[20][20], int rows, int cols)
{
	for (int k = 0; k < cols; ++k)
	{
		for (int i = 0; i < rows - 1; ++i)
		{
			for (int j = 0; j < rows - i - 1; ++j)
			{
				if(a[j][k] > a[j + 1][k])
				{
					int temp = a[j][k];
					a[j][k] = a[j + 1][k];
					a[j + 1][k] = temp;
				}
			}
		}
	}
}

int main()
{
	int a[20][20], rows, cols;
	
	input(a, rows, cols);
	print(a, rows, cols);
	
	changeRows(a, rows, cols);
	print(a, rows, cols);
	
	changeCols(a, rows, cols);
	print(a, rows, cols);
	
	return 0;
}

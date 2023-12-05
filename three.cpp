#include <iostream>
#include <iomanip>

using namespace std;

//a
void input(int a[20][20], int &rows, int &cols)
{
	cout << "Enter numbers of rows: ";
	cin >> rows;
	cout << "Enter numbers of columns: ";
	cin >> cols;
	
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cout << "Enter a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

//b
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

//c
int findMin(int a[20][20], int rows, int cols)
{
	int minValue = a[0][0];
	for (int i = 0; i < rows; ++i) 
	{
		for (int j = 0; j < cols; ++j)
		{
			if (a[i][j] < minValue)
			{
				minValue = a[i][j];
			}
		}
	}
	
	return minValue;
}

//d
int sum(int a[20][20], int rows, int cols)
{
	int sum = 0;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			sum += a[i][j];
		}
	}
	
	return sum;
}

//e
int countAppearanceX(int a[20][20], int rows, int cols, int &x)
{
	cout << "Enter x = ";
	cin >> x;
	
	int count = 0;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (a[i][j] == x)
			{
				count++;
			}
		}
	}
	
	return count;
}

//f
void countAppearance(int a[20][20], int rows, int cols)
{
	int b[400];
	int bSize = 0;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			b[bSize] = a[i][j];
			bSize++;
		}
	}
	
	for (int i = 0; i < bSize - 1; ++i)
	{
		for (int j = 0; j < bSize - i - 1; ++j)
		{
			if (b[j] > b[j + 1])
			{
				int temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
		}
	}
	
	int count = 1;
	int position = 0;
	while (position < bSize)
	{
		for (int i = 0; i < bSize; ++i)
		{
			if (b[i] > 0 && b[i] == b[position] && b[i] == b[i + 1])
			{
				position++;
				count++;
			}
		}
		cout << b[position] << " appears " << count << " times" << endl;
		position++;
		count = 1;
	}
}

//g
int positiveSum(int a[20][20], int rows, int cols)
{
	int sum = 0;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (a[i][j] >= 0)
			{
				sum += a[i][j];
			}
		}
	}
	
	return sum;
}

//h
int findMax(int a[20][20], int rows, int cols)
{
	int maxValue = a[0][0];
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0 ; j < cols; ++j)
		{
			if (a[i][j] > maxValue)
			{
				maxValue = a[i][j];
			}
		}
	}
	
	return maxValue;
}

void positionOfMax(int a[20][20], int rows, int cols, int &m, int &n)
{
	bool flag = false;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (a[i][j] == findMax(a, rows, cols))
			{
				m = i;
				n = j;
				flag = true;
				break;
			}
		}
		
		if (flag == true)
		{
			break;
		}
	}
}

//i
int maxRow(int a[20][20], int rows, int cols)
{
	int max = 0;
	for (int i = 0; i < rows; ++i)
	{
		int sum = 0;
		for (int j = 0; j < cols; ++j)
		{
			sum += a[i][j];
		}
		
		if (sum > max)
		{
			max = sum;
		}
	}
	
	return max;
}

int positionMaxRow(int a[20][20], int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		int sum = 0;
		for (int j = 0; j < cols; ++j)
		{
			sum += a[i][j];
		}
		if (sum == maxRow(a, rows, cols)) 
		{
			return i;
		}
	}
}

//j
int minCol(int a[20][20], int rows, int cols)
{
	int min = INT_MAX;
	for (int i = 0; i < cols; ++i)
	{
		int sum = 0;
		for (int j = 0; j < rows; ++j)
		{
			sum += a[j][i];
		}
		
		if (sum < min) 
		{
			min = sum;
		}
	}
	
	return min;
}

int positionMinCol(int a[20][20], int rows, int cols)
{
	for (int i = 0; i < cols; ++i)
	{
		int sum = 0;
		for (int j = 0; j < rows; ++j)
		{
			sum += a[j][i];
		}
		
		if (sum == minCol(a, rows, cols))
		{
			return i;
		}
	}
}

//k
void parallel(int a[20][20], int rows, int cols, int &k)
{
	cout << "k = ";
	cin >> k;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (k == j - i)
			{
				cout << a[i][j] << " ";
			}
		}
	}
	cout << endl;
	
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (k == i - j)
			{
				cout << a[i][j] << " ";
			}
		}
	}
}

int main()
{
	int a[20][20], rows, cols , x;
	//a b 
	input(a, rows, cols);
	print(a, rows, cols);
	
	//c
	cout << "Min = " << findMin(a, rows ,cols) << endl;
	
	//d
	cout << "Sum = " << sum(a, rows, cols) << endl;
	
	//e
	cout << x << " appears " << countAppearanceX(a, rows, cols, x) << " times" << endl;
	
	//f
	countAppearance(a, rows, cols);
	
	//g
	cout << "Sum of positive numbers = " << positiveSum(a, rows, cols) << endl;
	
	//h
	int m, n;
	positionOfMax(a, rows, cols, m, n);
	cout << "Max = " << findMax(a, rows, cols) << " at a[" << m << "][" << n << "]" << endl;	
	
	//i
	cout << "Position of max row: " << positionMaxRow(a, rows, cols) << "(" << maxRow(a, rows, cols) << ")" << endl;
	
	//j
	cout << "Position of min column: " << positionMinCol(a, rows, cols) << "(" << minCol(a, rows, cols) << ")" << endl;
	
	//k
	int k;
	parallel(a, rows, cols, k);
	
	return 0;
}

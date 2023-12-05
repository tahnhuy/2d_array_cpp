#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

void inputValue(int a[20][20], int &level)
{
	cout << "Enter the level of matrix: ";
	cin >> level;
	
	srand(time(0));
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			a[i][j] = rand() % 20 + 1;
		}
	}
}

void printValue(int a[20][20], int level)
{
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//a
void upTriangle(int a[20][20], int level)
{
	for (int i = 0; i < level - 1; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
		 	cout << setw(4) << " ";
		}
		
		for (int j = i + 1 ; j < level; ++j)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//b
void downTriangle(int a[20][20], int level)
{
	for (int i = 1; i < level; ++i)
	{
		for (int j = 0; j < i ; ++j)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//c
void identityMatrix(int identity[20][20], int level)
{
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			if (i == j)
			{
				identity[i][j] = 1;
				cout << setw(4) << identity[i][j];
			} else 
			{
				identity[i][j] = 0;
				cout << setw(4) << identity[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;
}

//d
void symmetricMatrix(int symmetric[20][20], int level)
{
	srand(time(0));
	for (int i = 0; i < level; ++i)
	{
		for (int j = i; j < level; ++j)
		{
			symmetric[i][j] = rand() % 50 + 1;
			symmetric[j][i] = symmetric[i][j];
		}
	}
}

//e
int sumUpTriangle(int a[20][20], int level)
{
	int sum = 0;
	for (int i = 0; i < level - 1; ++i)
	{
		for (int j = i + 1; j < level; ++j)
		{
			sum += a[i][j];
		}
	}
	return sum;
}

//f
bool isPrime(int n)
{
	if (n < 2)
	{
		return false;
	} else
	{
		for (int i = 2; i <= sqrt(n); ++i)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int sumK(int a[20][20], int level, int &k)
{
	int sum = 0;
	cout << "Enter postion of line k: ";
	cin >> k;
	
	for (int i = 0; i < level; ++i)
	{
		if (isPrime(a[k][i])) 
		{
			sum += a[k][i];
		}
	}
	
	return sum;
}

//g
void delLineK(int a[20][20], int level, int &k1)
{
	int temp[20][20];
	int tempRow  = level;
	int tempCol = level;
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			temp[i][j] = a[i][j];
		}
	}
	
	cout << "Enter position of line k1: ";
	cin >> k1;
	
	for (int i = k1; i < tempRow; ++i)
	{
		for (int j = 0; j < tempCol; ++j)
		{
			temp[i][j] = temp[i + 1][j];
		}
	}
	tempRow--;
	
	for (int i = 0;i < tempRow; ++i)
	{
		for (int j = 0; j < tempCol; ++j)
		{
			cout << setw(4) << temp[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//h
void delRowL(int a[20][20], int level, int &l)
{
	cout << "Enter position of l: ";
	cin >> l;
	
	int temp[20][20];
	int rows = level;
	int cols = level;
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			temp[i][j] = a[i][j];
		}
	}
	
	for (int i = 0; i < rows; ++i)
	{
		for (int j = l; j < cols; ++j)
		{
			temp[i][j] = temp[i][j + 1];
		}
	}
	cols--;
	
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cout << setw(4) << temp[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void insertRowK(int a[20][20], int level, int &k2)
{
	cout << "Enter position of k2: ";
	cin >> k2;
	
	int b[20];
	srand(time(0));
	for (int i = 0; i < level; ++i)
	{
		b[i] = rand() % 50 + 1;
	}
	
	int temp[20][20];
	int rows = level;
	int cols = level;
	
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			temp[i][j] = a[i][j];
		}
	}
	
	for (int i = rows; i > k2; --i)
	{
		for (int j = 0; j < cols; ++j)
		{
			temp[i][j] = temp[i - 1][j];
		}
	}
	rows++;
	
	for (int i = 0; i < cols; ++i)
	{
		temp[k2][i] = b[i];
		cout << b[i] << " ";
	}
	cout << endl;
	
	
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cout << setw(4) << temp[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//j
int calSumRow(int a[20][20], int k, int level)
{
	int sum = 0;
	for (int i = 0; i < level; ++i)
	{
		sum += a[k][i];
	}
	return sum;
}

void exJ(int a[20][20], int level)
{
	int sumOfRows[20];
	for (int i = 0; i < level; ++i)
	{
		sumOfRows[i] = calSumRow(a, i, level);
	}
	
	int position[20];
	for (int i = 0; i < level; ++i)
	{
		position[i] = i;
	}
	
	for (int i = 0; i < level - 1; ++i)
	{
		for (int j = 0; j < level - i - 1; ++j)
		{
			if (sumOfRows[j] < sumOfRows[j + 1]) 
			{
				int temp1 = sumOfRows[j];
				sumOfRows[j] = sumOfRows[j + 1];
				sumOfRows[j + 1] = temp1;
				
				int temp2 = position[j];
				position[j] = position[j + 1];
				position[j + 1] = temp2;
			}
		}
	}
	
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			cout << a[position[i]][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//k
int findMax(int a[20][20], int level)
{
	int max = a[0][0];
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
			}
		}
	}
	return max;
}

void delMax(int a[20][20], int level)
{
	int posRow = 0;
	int posCol = 0;
	int temp[20][20];
	int tempRow = level;
	int tempCol = level;
	
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			if (a[i][j] == findMax(a, level))
			{
				posRow = i;
				posCol = j;
				i = level;
				break;
			}
		}
	}
	
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			temp[i][j] = a[i][j];
		}
	}
	cout << "Max = " << findMax(a, level) << endl;
	cout << "Matrix a: " << endl;
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			cout << setw(4) << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i = posRow; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			temp[i][j] = temp[i + 1][j];
		}
	}
	tempRow--;
	
	for (int i = 0; i < tempRow; ++i)
	{
		for (int j = posCol; j < level; ++j)
		{
			temp[i][j] = temp[i][j + 1];
		}
	}
	tempCol--;
	
	for (int i = 0; i < tempRow; ++i)
	{
		for (int j = 0; j < tempCol; ++j)
		{
			cout << setw(4) << temp[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//l
int findRowPrimeMax(int a[20][20], int level)
{
	int maxRow = -1;
	int maxCount = 0;
	int count = 0;
	for (int i = 0; i < level; ++i) 
	{
		for (int j = 0; j < level; ++j) 
		{
			if (isPrime(a[j][i]))
			{
				count++;
			}
		}
		if (count > maxCount)
		{
			maxCount = count;
			maxRow = i;
		}
	}
	
	return maxRow;
}

void delMaxRow(int a[20][20], int level)
{
	int temp[20][20];
	int tempCol = level;
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			temp[i][j] = a[i][j];
		}
	}
	
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i = 0; i < level; ++i)
	{
		for (int j = findRowPrimeMax(a, level); j < level; ++j)
		{
			temp[i][j] = temp[i][j + 1];
		}
	}
	tempCol--;
	
	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < tempCol; ++j)
		{
			cout << setw(4) << temp[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int a[20][20], level;
	
	cout << "Enter & Print value" << endl;
	inputValue(a, level);
	printValue(a, level);
	
	//a b
	cout << "a + b" << endl;
	upTriangle(a, level);
	downTriangle(a, level);
	
	//c
	cout << "c" << endl;
	int identity[20][20];
	identityMatrix(identity, level);
	
	//d
	cout << "d" << endl;
	int symmetric[20][20];
	symmetricMatrix(symmetric, level);
	printValue(symmetric, level);
	
	//e
	cout << "e" << endl;
	cout << "Sum of upper triangle matrix: " << sumUpTriangle(a, level) << endl;
	
	//f
	cout << "f" << endl;
	int k;
	cout << "Sum of prime numbers in line "<< k << ": " << sumK(a, level, k) << endl;
	
	//g 
	cout << "g" << endl;
	int k1;
	delLineK(a, level, k1);
	
	//h
	cout << "l" << endl;
	int l;
	delRowL(a, level, l);
	
	//i
	cout << "i" << endl;
	int k2;
	insertRowK(a, level, k2);
	
	//j
	cout << "j" << endl;
	exJ(a, level);
	
	//k
	cout << "k" << endl;
	delMax(a, level);
	
	//l
	cout << "l" << endl;
	delMaxRow(a, level);
	
	return 0;
}

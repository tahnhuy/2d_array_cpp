#include <iostream>
#include <ctime>

using namespace std;

int main() {
	char a[7][7];
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			a[i][j] = 65;
		}
	}
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}

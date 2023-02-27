#include<iostream>
#include<cmath>

using namespace std;


void hanoi(int a, int b, int n) {  //어디에서 어디로 , 몇개

	if (n == 1) {
		cout << "\n" << a << ' ' << b;
		return;
	}
	hanoi(a, 6 - a - b, n - 1);
	cout << "\n" << a << ' ' << b;
	hanoi(6 - a - b, b, n - 1);

	return;

}

int main() {

	int N;

	cin >> N;

	cout << (1<<N)-1;
	hanoi(1, 3, N);

	return 0;

}
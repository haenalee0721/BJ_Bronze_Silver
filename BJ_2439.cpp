#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int a;
	cin >> a;

	for (int i = 0; i < a; i++) {
		for (int j = a - i-1; j > 0; j--) {
			cout << " ";
		}
		for (int k = a-i-1; k < a; k++) {
			cout << "*";
		}
		cout << "\n";
	}

}
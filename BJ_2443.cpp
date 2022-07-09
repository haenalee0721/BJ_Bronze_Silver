#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int a;
	cin >> a;

	for (int i = 0; i < a; i++) {
		for (int j =0; j < i; j++) {
			cout << " ";
		}
		for (int k = 2*a - 2*i - 1; k >0; k--) {
			cout << "*";
		}
		
		cout << "\n";
	}

}
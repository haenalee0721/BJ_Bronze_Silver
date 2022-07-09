#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int a,b,c;
	cin >> a;

	for (int i = 0; i < a; i++) {
		cin >> b >> c;
		cout << b + c << "\n";
	}

}
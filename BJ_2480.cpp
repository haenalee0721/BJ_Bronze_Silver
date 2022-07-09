//주사위 세개
#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b>> c;

	if (a == b && b == c) {
		cout << 10000 + (a * 1000);
	}
	else if (a == b)
		cout << 1000 + (a * 100);
	else if (b == c)
		cout << 1000 + (b* 100);
	else if (a == c)
		cout << 1000 + (a * 100);
	else {
		if (a > b && a > c) {
			cout << a * 100;
		}
		else if (b > a && b > c) {
			cout << b * 100;
		}
		else {
			cout << c * 100;
		}
	}
	
}
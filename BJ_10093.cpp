#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	long long a, b;
	cin >> a >> b;

	if (a >b) {
		swap(a, b); // algorithm ����� ����ִ� swap �Լ�
	}if (a == b) {
		cout << 0;
	}
	else {

	cout << b - a - 1 << "\n";
	for (long long i = a + 1; i < b; i++) {
		cout << i << " ";
	}
}

}

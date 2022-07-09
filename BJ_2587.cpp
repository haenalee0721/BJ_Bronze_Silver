//´ëÇ¥°ª2

#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int A[5];
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		cin >> A[i];
		sum += A[i];
	}

	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 5; j++) {
			if (A[i] > A[j]) {
				int p = A[i];
				A[i] = A[j];
				A[j] = p;
			}
		}
	}

	cout << sum / 5 << "\n" << A[2];

}
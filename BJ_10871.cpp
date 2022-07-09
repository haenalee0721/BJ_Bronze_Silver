//x보다 작은 수

#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int N = 0;
	int X=0;
	cin >> N;
	cin >> X;

	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		if (A < X) {
			cout << A<<' ';
		}
	}
}
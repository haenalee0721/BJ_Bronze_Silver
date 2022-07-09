#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int f;
	int a;
	cin >> f;
	int Y = 0;
	int M = 0;

	for (int i = 0; i < f; i++) {
		cin >> a;
		Y += ((a / 30) + 1)*10;
		M += ((a / 60) + 1) * 15;
	}

	
	if (Y < M) {
		cout << "Y  " << Y;
	}else if (Y >M) {
		cout << "M  " << M;
	}
	else {
		cout << "Y "<<"M  " << M;
	}

}

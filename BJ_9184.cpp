#include <iostream>

using namespace std;
int abc[51][51][51];

int w(int a, int b, int c) {

	if (a <= 0 || b <= 0 || c <= 0) return 1;

	if (abc[a][b][c]) {
		return abc[a][b][c];
	}

	else if (a > 20 || b > 20 || c > 20) {
		int x= w(20, 20, 20);
		abc[a][b][c] = x;
		return x;
	}
	else if (a <b && b < c ) {
		int x= w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		abc[a][b][c] = x;
		return x;
	}
	else {
		int x = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		abc[a][b][c] = x;
		return x;
	}
}

int main() {

	int a, b, c;

	while (1) {

		cin >> a >> b >> c;
		if (a == -1&&b==-1&&c==-1) break;  //��������

		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a, b, c)<<endl;

	}
}
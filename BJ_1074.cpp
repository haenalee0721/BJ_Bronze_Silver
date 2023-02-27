#include<iostream>

using namespace std;

int A, B,N;

int power(int n, int k) {
	if (k == 0) return 1;
	return n * power(n, k - 1);
}

int Z(int x, int y, int n) {


	if (n == 0) {
		return 0;
	}

	int k = power(2, n - 1);
	
	if (x <= A && A < k+x  && y <= B && B < k +y) {  //1
		return Z(x, y, n - 1);
	}
	else if (x <= A && A < k +x && k+y <= B && B < y+2*k) { //2
		return k*k+Z(x, y + k, n - 1);
	}
	else if (x+k <= A && A < x+k*2  && y <= B && B < k +y) {  //3
		return 2*k*k + Z(x + k, y, n - 1);
	}
	else { //4
		return 3 * k * k + Z(x + k, y + k, n - 1);
	}


}

int main() {

	cin >> N >> A >> B;

	cout<<Z(0, 0, N);

}
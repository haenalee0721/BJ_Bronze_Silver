#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int a, b, c,sum;
	int num[10] = { 0, };
	cin >> a >> b >> c;

	sum = a * b * c;
	int N,D=10,B=1;

	while (sum>D) {

		D *= 10;
		B++;
	}
	D = 10;
	
	for (int i = 0; i < B; i++) {
		N = sum % D;
		num[N]++;
		sum /= 10;
		
	}

	

	for (int i = 0; i < 10; i++) {
		cout << num[i] << "\n";
	}


}
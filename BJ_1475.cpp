#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	long long sum=1;
	long long num[10] = { 0, };
	cin >> sum;


	while (sum) {

		num[sum % 10]++;
		sum /= 10;

	}

	long long  Big = 1;
	int index=0;

	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) continue;
		Big = max(Big, num[i]);
	}
	


	cout << max(Big, (num[6] + num[9]) / 2 + (num[6] + num[9]) % 2);
	
}
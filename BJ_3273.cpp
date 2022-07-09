#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int num ;
	int* arr;
	
	cin >> num;
	arr = new  int[num];

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	int sum=10,fre=0;
	cin >> sum;

	int* N = new  int[sum+1];

	for (int i = 0; i < sum+1; i++) {
		N[i] = 0;
	}

	for (int i = 0; i < num; i++) {
		if (sum >= arr[i]) {
			if (N[sum - arr[i]]) fre++;
			N[arr[i]]++;
		}
	
	}

	cout << fre;

	delete[] N;
	delete[] arr;

}
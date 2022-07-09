#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int num[21];
	
	for (int i = 1; i < 21; i++) num[i] = i ;

	for (int j = 0; j < 10; j++) {
	
		int a, b;
		cin >> a >> b;

		for (int i = 0; i <( b - a + 1)/2;i++) 
			swap(num[a + i], num[b - i]);
	}

	for (int i = 1; i < 21; i++) cout << num[i] << " ";

}

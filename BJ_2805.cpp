#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int *tree;
	int H, sum,num,M;

	cin >> num >> H;

	tree= new int[num];

	for (int i = 0; i < num; i++) 	cin >> tree[i];
	
	int max; ;
	max = tree[0];

	for (int i = 1; i < num; i++) {
		if (max < tree[i]) max = tree[i];
	}
	M = max;
	do{
		sum = 0;

		for (int i = 0; i < num; i++) {

			if (tree[i] > M)  sum += (tree[i] - M);

		}

		M--;
	}while(sum < H);

	cout << M+1;
	delete[] tree;

}
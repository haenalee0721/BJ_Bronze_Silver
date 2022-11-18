#include <iostream>
#include <list>

using namespace std;

int main() {

	int N, k,a;

	cin >> N;
	cin >> k;
	list<int> score;
	list<int>::iterator iter;

	for (int i = 0;i < N; i++) {
		cin >> a;
		score.push_back(a);
	}

	score.sort();
	iter = score.end();

	for (int i = 0;i < k; i++) { 
		iter--;
	}

	cout << *iter;

	return 0;
}

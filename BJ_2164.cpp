#include <iostream>
#include<queue>

using namespace std;

int main() {

	queue<int> p;

	int N,s=0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		p.push(i);
	}

	while(p.size()!=1){
		if (s %2== 0) {
			p.pop();
			s++;
		}
		else {
			p.push(p.front());
			p.pop();
			s++;
		}

	}

	cout << p.front();
	
}
#include <iostream>
#include <stack>

using namespace std;

int main() {

	int K,a,sum=0;
	cin >> K;

	stack<int> s;

	for (int i = 0; i < K; i++){
		cin >> a;
		if (a == 0) {
			s.pop();
		}
		else {
			s.push(a);
		}

	}
	a = s.size();
	for (int i = 0; i < a; i++) {
		sum += s.top();
		s.pop();
	}

	cout << sum;
}
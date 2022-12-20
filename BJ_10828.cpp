#include <iostream>
#include<string>
#include <stack>

using namespace std;

int main() {

	int n=0,b=0,c=0;
	string a;
	stack<int> s;

	cin >> n;

	int* result = new int[n];

	
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == "push") {
			cin >> b;
			s.push(b);
		}else if(a == "top") {
			if (s.empty()) { result[c] = -1; c++; }
			else {
				result[c] = s.top();
				c++;
			}
		}
		else if (a == "size") {
			result[c] = s.size();
			c++;
		}
		else if (a == "empty") {
			if (s.empty()) {
				result[c] = 1; c++;
			}
			else {
				result[c] = 0; c++;
			}
		}
		else {
			if (s.empty()) {
				result[c] = -1; c++;
			}
			else {
				result[c] = s.top(); c++;
				s.pop();
			}
		}
		
	}

	for (int i = 0; i < c-1; i++) {
		cout << result[i] << "\n";
	}cout << result[c - 1];

	delete[] result;
}
#include <iostream>
#include<string>
#include <stack>

using namespace std;

int main() {

	int n,b;
	string a;
	stack<int> s;

	int* result = new int[n];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == "push") {
			cin >> b;
			s.push(b);
		}else if(a == "top") {
			if (s.empty()) cout << -1<<"\n";
			else cout<<s.top()<<"\n";
		}
		else if (a == "size") {
			cout << s.size() << "\n";
		}
		else if (a == "empty") {
			if (s.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else {
			if (s.empty()) cout << -1 << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		
	}
}
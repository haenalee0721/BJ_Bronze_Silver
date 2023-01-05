#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);


	while (1) {
		string charInput;
		getline(cin, charInput);
		if (charInput == ".") { return 0; }//Á¾·á
		stack<char> s;
		
		for (auto c: charInput) {
			if (c == '.') {
				if (s.empty()) {
					cout << "yes\n";
					break;
				}
				else {
					cout << "no\n";
					break;
				}

			}
			else if (c == '[' || c == '(') {
				s.push(c);
			}
			else if (c== ']'|| c== ')') {
				if (s.empty()) {
					cout << "no\n";
					break;
				}
				if ((s.top() == '['&&c == ']')||(s.top() == '(' && c == ')')) {
					s.pop();
				}
				else {
					cout << "no\n";
					break;
				}
			}
		}
	}
		return 0;
}
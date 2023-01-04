#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {

	char charInput[100];
	

	while (1) {
		cin.getline(charInput, 100);
		stack<char> s;
		if (charInput[0] == '.') { return 0; }
		for (int i = 0; i < 100; i++) {
			if (charInput[i] == '.') {
				cout << "yes";
				break;
			}
			else if (charInput[i] == '[' || charInput[i] == '(') {
				s.push(charInput[i]);
			}
			else if (charInput[i] == ']') {
				if (s.empty()) {
					cout << "no" << endl;
					break;
				}
				if (s.top() == '[') {
					s.pop();
				}
				else {
					cout << "no" << endl;
					break;
				}
			}
			else if (charInput[i] == ')') {
				if (s.empty()) {
					cout << "no" << endl;
					break;
				}
				if (s.top() == '(') {
					s.pop();
				}
				else {
					cout << "no" << endl;
					break;
				}
			}
		}
	}

		return 0;
}
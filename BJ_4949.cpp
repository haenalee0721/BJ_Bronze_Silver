#include<iostream>
#include<string>
#include<stack>


int main() {

	char charInput[100];
	stack<char> s;

	while (charInput[0] != '.') {
		cin.getline(charInput, 100);
		for (int i = 0; i < 100; i++) {
			if (charInput[i] == '.') {
				cout << "yes";
				return;
			}
			else if (charInput[i] == '{' || charInput[i] == '(') {
				s.push(charInput[i]);
			}
			else if (charInput[i] == '}') {
				if (s.top() == '{') {
					s.pop();
				}
				else {
					cout << "no" << endl;
					break;
				}
			}
			else if (charInput[i] == ')') {
				if (s.top() == '(') {
					s.pop();
				}
				else {
					cout << "no" << endl;
					break;
				}
			else continue;
		}
	}

}
#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N,cnt=0;
	cin >> N;


	for(int i=0;i<N;i++){
		string charInput;
		getline(cin, charInput);

		if (charInput.empty()) { i--; continue; }
		stack<char> s;

		for (auto c : charInput) {
			
			if (s.empty()) {
				s.push(c);
			}
			else {
				if (s.top() == c) {
					s.pop();
				}
				else {
					s.push(c);
				}
				
			}
			
		}
		if (s.empty()) {  cnt++; }
	}
	std::cout << cnt;
	return 0;
}
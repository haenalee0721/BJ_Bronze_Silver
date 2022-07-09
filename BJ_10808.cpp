// 알파벳 개수세기

#include <iostream>
#include <string>

using namespace std;

int main() {

	string s;
	cin >> s;
	int A[26] = {0,};  // 전역변수로 선언하면 0으로 세팅
	for (auto c : s) 
		A[c - 'a']++;
	for (int a : A) 
		cout << a << " ";
}
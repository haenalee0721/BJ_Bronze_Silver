// ���ĺ� ��������

#include <iostream>
#include <string>

using namespace std;

int main() {

	string s;
	cin >> s;
	int A[26] = {0,};  // ���������� �����ϸ� 0���� ����
	for (auto c : s) 
		A[c - 'a']++;
	for (int a : A) 
		cout << a << " ";
}
#include <iostream>


using namespace std;

int main() {

	int a;
	cin >> a;
	
	int* p = new int[a];
	for (int i = 0; i < a; i++) {
		p[i] = i + 1;
	}
	int b;
	cin >> b;

	cout << "<";
	int index = -1;
	for (int i = 0; i < a; i++) {

		for (int j = 0; j < b; j++) {
			index++;
			if (index == a)index = 0;
			if (p[index] == -1)j--;
		}
		if (i == a - 1) {
			break;
		}cout << p[index] << ", "; p[index] = -1;
	}

	cout << p[index] << ">";


}
#include <iostream>
#include <stack>
#include <array>

using namespace std;

stack<int> S;

void dfs(int* V, int** E, int R) {

	//int* V = new int[Vnum];

	V[R] = 1;
	cout << R << endl;
	int size = (_msize(V) / sizeof(*V));
	for (int i = 1; i < size; i++) {
			if (E[R][i] == 1) {
				if (V[i] != 0) dfs(V, E, i);
		}
	}
	

}

int main() {

	int Vnum, Enum, R;
	cin >> Vnum >> Enum >> R;
	Vnum += 1;
	Enum += 1;
	int* V = new int[Vnum];
	int** E = new int*[Vnum];
	for (int i = 0; i < Vnum; i++) {
		E[i] = new int[Vnum];
		V[i] = 0;
	}

	for (int i = 0; i < Vnum; i++) {
		for (int j = 0; j < Vnum; j++) {
			E[i][j] = 0;
		}
	}
	

	int a, b;

	for (int i = 1; i < Enum; i++) {
		cin >> a >> b;
		E[a][b] = 1;
		E[b][a] = 1;
	}

	dfs(V, E, R);
}
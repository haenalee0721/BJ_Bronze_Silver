#include <iostream>
#include <vector>

using namespace std;

int num = 1;

void dfs(int** E, int R,int size) {

	E[R][0] = num++;

	for (int i = 1; i < size; i++) {
		if (E[R][i] == 1) {
			if (E[i][0] == 0) dfs( E, i, size);
		}
	}

}

int main() {

	int Vnum, Enum, R;
	cin >> Vnum >> Enum >> R;
	Vnum += 1;
	Enum += 1;

	int** E = new int* [Vnum];
	for (int i = 0; i < Vnum; i++) {
		E[i] = new int[Vnum];
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

	dfs(E, R, Vnum);

	for (int i = 1; i < Vnum; i++) {
		cout << E[i][0] << endl;
	}
}
#include <iostream>
#include <vector>

using namespace std;

int num = 1;

void dfs(vector < vector <int> >& E, int R) {

	E[R][0] = num++;

	for (int i = 1; i < E.size(); i++) {
		if (E[R][i] == 1) {
			if (E[i][0] == 0) dfs( E, i);
		}
	}

}

int main() {

	int Vnum, Enum, R;
	cin >> Vnum >> Enum >> R;
	Vnum += 1;
	Enum += 1;

	vector<vector<int>> node(Vnum, vector<int>(Vnum, 0));

	int a, b;

	for (int i = 1; i < Enum; i++) {
		cin >> a >> b;
		node[a][b] = 1;
		node[b][a] = 1;
	}

	dfs(node, R);

	for (int i = 1; i < Vnum; i++) {
		cout << node[i][0] << endl;
	}
}
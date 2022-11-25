#include <iostream>

using namespace std;

int num;

void dfs(int* V, int* E, int R, int size) {


	V[R] = ++num; 
	cout << V[R]<<endl;

	for (int i = 1; i < size; i++) {
			if (E[R*size +i] == 1) {
				if (V[i] == 0) dfs(V, E, i,size);
		}
	}
	
}

int main() {

	int Vnum, Enum, R,i;
	cin >> Vnum >> Enum >> R;
	Vnum ++;
	Enum ++;
	int* V = new int[Vnum];
	int* E = new int[Vnum* Vnum];
	
	for (i = 0; i < Vnum; i++) V[i] = 0;
		

	for (i = 0; i < Vnum * Vnum; i++) E[i] = 0;


	int a, b;

	for (i = 1; i < Enum; i++) {
		cin >> a >> b;
		E[a* Vnum+b] = 1;
		E[b * Vnum+a] = 1;
	}

	dfs(V, E, R, Vnum);

}
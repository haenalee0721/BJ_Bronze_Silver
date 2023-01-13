#include<iostream>
#include<vector>
#include<queue>
#include<string>


using namespace std;

int check[100][100];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m,num=0;
	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};
	int a[100][100];
	string line;

	queue<pair<int, int>> Q;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		getline(cin, line);
		int j=0;
		for (auto c : line) {
			a[i][j++] = c;
		}
	}

	while(!Q.empty()) {
		pair<int, int> C = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = C.first + dx[i];
			int ny = C.second + dy[i];

			if (nx<0 || nx>n || ny<0 || ny>m) continue;
			if (a[nx][ny] == 0 || check[nx][ny] == 1) continue;

			check[nx][ny] =1;
			Q.push({ nx,ny });
			num++;
		}

	}

	cout << num;
}
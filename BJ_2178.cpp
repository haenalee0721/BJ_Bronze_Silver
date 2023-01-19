#include<iostream>
#include<vector>
#include<queue>
#include<string>


using namespace std;

int check[100][100];
int n, m;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
string a[100];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	check[0][0] = 1;


	while (!Q.empty()) {
		auto C = Q.front();

		Q.pop();
	

		for (int i = 0; i < 4; i++) {
			int nx = C.first + dx[i];
			int ny = C.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (a[nx][ny] == '0' || check[nx][ny] >= 1) {
				continue;
			}

			check[nx][ny] = check[C.first][C.second] + 1;
			Q.push({ nx,ny });

		}
	}

	cout << check[n - 1][m - 1];
}
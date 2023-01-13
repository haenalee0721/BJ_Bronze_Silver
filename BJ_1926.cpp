#include<iostream>
#include<vector>
#include<queue>


using namespace std;

int check[500][500];

int main() {

	int n, m,max=0,num=0;

	int a[500][500];
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] && !check[i][j]) { //�湮���ߴ� 1�̶�� BFS����
				int w = 0;
				num++;
				queue<pair<int, int> > Q;
				check[i][j] = 1; // (0, 0)�� �湮�ߴٰ� ���
				Q.push({ i,j }); // ť�� �������� (0, 0)�� ����.
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					w++;
					for (int i = 0; i < 4; i++) {
						int nx = cur.first + dx[i];
						int ny = cur.second + dy[i];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (check[nx][ny] || a[nx][ny] != 1) continue;

						check[nx][ny] = 1; // (nx, ny)�� �湮�ߴٰ� ���
						Q.push({ nx,ny });
					}
				}
				if (w > max) max = w;
			}
		}
	}

	
	cout << num << "\n" << max;

}
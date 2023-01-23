#include<iostream>
#include<queue>
#include<vector>


using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
queue<pair<int, int>> Q;
int tomato[1000][1000];
int check[1000][1000];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int num = 0, day = 0, n, m;

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {  //���� �丶�䰡 �ִٸ� �湮
				Q.push({ i,j }); check[i][j] = 1;
			}
		}
	}

	pair<int, int> C;


	while (!Q.empty()) {

		C = Q.front();
		Q.pop();


		for (int i = 0; i < 4; i++) {
			int nx = C.first + dx[i];
			int ny = C.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (tomato[nx][ny] != 0 || check[nx][ny] != 0) continue;

			tomato[nx][ny] = 1; //�;��ٰ� ǥ��
			check[nx][ny] = check[C.first][C.second] + 1; //�Ϸ� ���� ��¥ ǥ��
			Q.push({ nx,ny });
		}
	}

	for (int i = 0; i < n; i++) { //��� ������ ���ƴµ��� �������� �ִٸ� -1
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				cout << -1; return 0;
			}
		}
	}

	cout << check[C.first][C.second] - 1;   //0��°���� 1�� �����ؼ� �Ϸ绩�ֱ�
	return 0;

}
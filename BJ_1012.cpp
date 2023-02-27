#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int farm[50][50];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {

	int a, num = 0,N, M ,K, x, y, flag = 0,sx,sy;
	cin >> a;

	for (int i = 0; i < a; i++) {  //�׽�Ʈ���̽���ŭ
		num = 0;
		queue<pair<int, int>> Q;
		flag = 0;

		cin >> M >> N >> K;

		for (int j = 0; j < K; j++) {  //�Է¹ޱ�
			cin >> y >> x;
			farm[x][y] = 1;
		}

		while (flag == 0) {  //��������

			for (int a = 0; a < N; a++) {  //1ã��
				for (int b = 0; b < M; b++) {
					if (farm[a][b] == 1) { Q.push({ a,b }); farm[a][b] = 0; goto start; }
				}
			} flag = 1; continue;  //�ѹ��� �׽�Ʈ���̽� ����

		start:  //BFS����

			while (!Q.empty()) {
				pair<int, int > C = Q.front();
				Q.pop();

				for (int j = 0; j < 4; j++) {
					int nx = C.first + dx[j];
					int ny = C.second + dy[j];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (farm[nx][ny] == 0) continue;

					Q.push({ nx,ny });
					farm[nx][ny] = 0;
				}
			} num++;
		}
		cout << num << "\n";
	}

}
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

	for (int i = 0; i < a; i++) {  //테스트케이스만큼
		num = 0;
		queue<pair<int, int>> Q;
		flag = 0;

		cin >> M >> N >> K;

		for (int j = 0; j < K; j++) {  //입력받기
			cin >> y >> x;
			farm[x][y] = 1;
		}

		while (flag == 0) {  //개수세기

			for (int a = 0; a < N; a++) {  //1찾기
				for (int b = 0; b < M; b++) {
					if (farm[a][b] == 1) { Q.push({ a,b }); farm[a][b] = 0; goto start; }
				}
			} flag = 1; continue;  //한번의 테스트케이스 종료

		start:  //BFS진행

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
#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

char miro[1000][1000];  //�̷�
int check[1000][1000];  //�湮 �� �Ÿ� üũ
int fire[1000][1000];  //�� ������

int main() {

	int R, C;
	int num=0; //���� �� �ִ� �Ұ���
	cin >> R >> C;
	int Jx, Jy, Fx, Fy;
	int dx[4] = {0,1,0,-1};
	int dy[4] = { 1,0,-1,0 };
	queue<pair<int, int>> Q;
	queue<pair<int, int>> F;

	string a;
	for (int i = 0; i < R; i++) {
		cin >>miro[i];
	}

	//��ȣ,�� ã��
	for (int i = 0; i < R; i++) {
		for (int j = 0; j< C; j++) {
			if (miro[i][j] == 'J') {
				Jx = i; Jy = j;
			}else if (miro[i][j] == 'F') {
				Fx = i; Fy = j;
			}
		}
	}
	
	check[Jx][Jy] = 1;
	fire[Fx][Fy] = 1;
	Q.push({ Jx,Jy });
	F.push({ Fx,Fy });


	//BFS
	while (!Q.empty()) {
		pair<int, int> Cu= Q.front();
		Q.pop();
		num = 0;

		//��������
		for (int i = 0; i < num; i++) {
			pair<int, int> FC = Q.front();
			F.pop();
			for (int i = 0; i < 4; i++) {
				int nx = FC.first + dx[i];
				int ny = FC.second + dy[i];

				if (nx <= 0 || ny <= 0 || ny >= C - 1 || nx >= R - 1) continue;
				if (fire[nx][ny] == 1 || miro[nx][ny] != '.')continue;

				F.push({ nx,ny });
				fire[ny][ny] = 1;
				num++;
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = Cu.first + dx[i];
			int ny = Cu.second + dy[i];

			if (nx <= 0 || ny <= 0 || ny>=  C-1 || nx >= R-1) continue; //�����ڸ��� ������ ����ó��
			if (check[nx][ny] == 1 || miro[nx][ny] != '.') continue;
			if (fire[nx][ny] == 1) continue;
		

			Q.push({ nx,ny });
			miro[nx][ny] = 1;
			check[nx][ny] = check[Cu.first][Cu.second]+1;

		}

	}

	//�ִܰŸ� ã��
	int max = 0;
	for (int i = 0; i < R; i++) {  //���� ������ �����ڸ� Ȯ��
		if (max < check[i][0]) max = check[i][0];
		if (max < check[i][C - 1]) max = check[i][C - 1];
	}
	for (int i = 0; i < C; i++) {  //���Ʒ� �����ڸ� Ȯ��
		if (max < check[0][i]) max = check[0][i];
		if (max < check[R-1][i]) max = check[R - 1][i];
	}

	if(max==0){
		cout << "IMPOSSIBLE";
	}else cout << max;
}
#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

char miro[1001][1001];  //미로
int check[1001][1001];  //방문 및 거리 체크
int fire[1001][1001];  //불 퍼지기

int main() {

	int R, C;
	int num=0,fre=0,n=1,f=0; //퍼질 수 있는 불개수
	cin >> R >> C;
	int Jx=0, Jy=0, Fx=0, Fy=0;
	int dx[4] = {0,1,0,-1};
	int dy[4] = { 1,0,-1,0 };
	queue<pair<int, int>> Q;
	queue<pair<int, int>> F;

	string a;
	for (int i = 0; i < R; i++) {
		cin >>miro[i];
	}

	//진호,불 찾기
	for (int i = 0; i < R; i++) {
		for (int j = 0; j< C; j++) {
			check[i][j] = -1;
			if (miro[i][j] == 'J') {
				Q.push({ i,j });
				check[i][j] = 0;
				//Jx = i; Jy = j;
			}else if (miro[i][j] == 'F') {
				F.push({ i,j });
				fire[i][j] = 1;
				fre++;
			}
		}
	}
	num = fre;
	fre = 0;


	//BFS
	while (!Q.empty()) {

		//불퍼지기
		for (int i = 0; i < num; i++) {
			pair<int, int> FC = F.front();
			F.pop();

			for (int j = 0;j < 4; j++) {
				int nx = FC.first + dx[j];
				int ny = FC.second + dy[j];

				if (nx < 0 || ny < 0 || nx >= C || nx >= R) continue;
				if (fire[nx][ny] == 1 || miro[nx][ny] != '.')continue;

				F.push({ nx,ny });
				fire[nx][ny] = 1;
				fre++;
				//cout << "F : " << nx << " , " << ny << " : " << num << endl;

			}

		}
		num = fre;
		fre = 0;
		



		//길찾기

		for (int j = 0; j < n; j++) {

			pair<int, int> Cu = Q.front();
			Q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = Cu.first + dx[i];
				int ny = Cu.second + dy[i];

				if (nx < 0 || ny < 0 || ny>  C - 1 || nx > R - 1) continue;
				if (check[nx][ny] > 1 || miro[nx][ny] != '.') continue;
				if (fire[nx][ny] == 1) continue;


				Q.push({ nx,ny });
				miro[nx][ny] = 1;
				if ((check[Cu.first][Cu.second] + 1) < check[nx][ny] || check[nx][ny] == -1)
					check[nx][ny] = check[Cu.first][Cu.second] + 1;
				f++;
				//cout << "C : " << nx << " , " << ny << " : " << check[nx][ny] << endl;
			}

		}

		n = f;
		f = 0;

	}

	//최단거리 찾기

	int min = 100;
	for (int i = 0; i < R; i++) {  //왼쪽 오른쪽 가장자리 확인
		if (min > check[i][0]&&check[i][0]!=-1) min = check[i][0];
		if (min > check[i][C - 1] && check[i][C - 1] != -1) min = check[i][C - 1];
	}
	for (int i = 0; i < C; i++) {  //위아래 가장자리 확인
		if (min > check[0][i] && check[0][i] != -1) min = check[0][i];
		if (min >check[R-1][i] && check[R - 1][i] != -1) min = check[R - 1][i];
	}

	if(min ==100||min==-1){
		cout << "IMPOSSIBLE";
	}else cout << min+1;
}
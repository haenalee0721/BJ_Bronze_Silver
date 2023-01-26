#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

char miro[1001][1001];  //�̷�
int check[1001][1001];  //�湮 �� �Ÿ� üũ
int fire[1001][1001];  //�� ������

int main() {

	int R, C;
	int num=0,fre=0; //���� �� �ִ� �Ұ���
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

	//��ȣ,�� ã��
	for (int i = 0; i < R; i++) {
		for (int j = 0; j< C; j++) {
			check[i][j] = 1;
			if (miro[i][j] == 'J') {
				Jx = i; Jy = j;
			}else if (miro[i][j] == 'F') {
				Fx = i; Fy = j;
				//fre++;
			}
		}
	}
	
	check[Jx][Jy] = 1;
	fire[Fx][Fy] = 1;
	Q.push({ Jx,Jy });
	//F.push({ Fx,Fy });

	//ù��° ��
	for (int i = 0; i < 4; i++) {
		int nx = Fx + dx[i];
		int ny = Fy + dy[i];

		if (nx < 0 || ny < 0 || nx >= C || nx >= R) continue;
		if (fire[nx][ny] == 1 || miro[nx][ny] == '#')continue;

		F.push({ nx,ny });
		fire[nx][ny] = 1;
		fre++;
		//cout << "F : " << nx << " , " << ny << " : " << num << endl;

	}
	num = fre;
	fre = 0;

	//BFS
	while (!Q.empty()) {


		//��ã��
		pair<int, int> Cu = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = Cu.first + dx[i];
			int ny = Cu.second + dy[i];

			if (nx < 0 || ny < 0 || ny>  C-1 || nx > R-1) continue; 
			if (check[nx][ny] > 1 || miro[nx][ny] != '.') continue;
			if (fire[nx][ny] == 1) continue;
		

			Q.push({ nx,ny });
			miro[nx][ny] = 1;
			if((check[Cu.first][Cu.second] + 1)<check[nx][ny]|| check[nx][ny] ==1)
				check[nx][ny] = check[Cu.first][Cu.second]+1;
			

			cout << "C : " << nx << " , " << ny << " : " << check[nx][ny] << endl;

		}

		//��������
		for (int i = 0; i < num; i++) {
			pair<int, int> FC = F.front();
			F.pop();

			for (int i = 0; i < 4; i++) {
				int nx = FC.first + dx[i];
				int ny = FC.second + dy[i];

				if (nx < 0 || ny < 0 || nx >= C || nx >= R) continue;
				if (fire[nx][ny] == 1 || miro[nx][ny] != '.')continue;

				F.push({ nx,ny });
				fire[nx][ny] = 1;
				fre++;
				//cout << "F : " << nx << " , " << ny << " : " << num << endl;

			}
			
		}

		fre = 0;
		num = fre;
		
	}

	//�ִܰŸ� ã��

	int min = 100;
	for (int i = 0; i < R; i++) {  //���� ������ �����ڸ� Ȯ��
		if (min > check[i][0]&&check[i][0]!=1) min = check[i][0];
		if (min > check[i][C - 1] && check[i][C - 1] != 1) min = check[i][C - 1];
	}
	for (int i = 0; i < C; i++) {  //���Ʒ� �����ڸ� Ȯ��
		if (min > check[0][i] && check[0][i] != 1) min = check[0][i];
		if (min >check[R-1][i] && check[R - 1][i] != 1) min = check[R - 1][i];
	}

	if(min ==100){
		cout << "IMPOSSIBLE";
	}else cout << min;
}
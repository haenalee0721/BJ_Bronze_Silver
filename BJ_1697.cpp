#include <iostream>
#include <Queue>

using namespace std;

int road[100001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	road[N]  =1;

	queue<int> Q;
	Q.push(N);

	while (road[K] == 0) {

		int a= Q.front();
		Q.pop();

		//앞으로
		if (a + 1 > 100000){}
		else{
			if (road[a + 1] == 0 || road[a + 1] > road[a] + 1) {
				road[a + 1] = road[a] + 1;
				Q.push(a + 1);
			}
		}
	
		//뒤로
		if (a - 1 < 0) {}
		else {
			if (road[a - 1] == 0 || road[a - 1] > road[a] + 1) {
				road[a - 1] = road[a] + 1;
				Q.push(a - 1);
			}
		}

		//두배
		if (a *2 > 100000){}
		else {
			if (road[a * 2] == 0 || road[a * 2] > road[a] + 1) {
				road[a * 2] = road[a] + 1;
				Q.push(a * 2);
			}
		}
	}
	cout << road[K] - 1;
	return 0;
}
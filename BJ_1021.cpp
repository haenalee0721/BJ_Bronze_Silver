#include <iostream>
#include<deque>

using namespace std;

int num[50];
int N, M, fre = 0;


int main() {

	
	deque<int> q;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < N; i++) {
		q.push_back(i + 1);
	}

	for (int i = 0; i < M; i++) {
		int f = q.size() / 2;
			if ((q.front() + f )%q.size()> num[i]) { //2단계 수행
				while (q.front() != num[i]) {
					q.push_back(q.front());
					q.pop_front();
					fre++;
				}q.pop_front();
			}
			else {  //3단계수행
				while (q.front() != num[i]) {
					q.push_front(q.back());
					q.pop_back();
					fre++;
				}q.pop_front();
			}
	
	}

	cout << fre;
}
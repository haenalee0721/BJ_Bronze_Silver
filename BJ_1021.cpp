#include <iostream>
#include<deque>

using namespace std;

int num[50];
int N, M, fre, idx = 0;


int main() {


	deque<int> q;
	deque<int>::iterator iter = q.begin();

	cin >> N >> M;
	for (int i = 0; i < M; i++) {  //찾아야하는 수 배열에 넣기
		cin >> num[i];
	}
	for (int i = 0; i < N; i++) {  //순서대로 숫자넣기
		q.push_back(i + 1);
	}

	for (int i = 0; i < M; i++) {//모든수를 찾을때까지 반복
		int f = (q.size() / 2);
		idx = 0;

		for (iter = q.begin(); iter != q.end(); ++iter) {
			if (num[i] == *iter) break;
			idx++;
		}
		if (num[i] == q.front()) {  //맨앞에 원하는게 있다면 넘기기
			q.pop_front();
			continue;
		}

		if (idx <= f) {
			while (q.front() != num[i]) { //왼쪽으로이동
				q.push_back(q.front());
				q.pop_front();
				fre++;
			}q.pop_front();
		}
		else {  //3단계수행
			while (q.front() != num[i]) { //오른쪽으로이동
				q.push_front(q.back());
				q.pop_back();
				fre++;
			}q.pop_front();
		}
	}

	cout << fre;
}
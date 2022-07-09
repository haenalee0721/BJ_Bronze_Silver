#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int fre;
	cin >> fre;

	for (int i = 0; i < fre; i++) {
		list<char> L;
		list<char>::iterator t = L.begin();
		
		string pass;
		cin >> pass;

		for (auto c : pass) {
			if (c == '-') {
				if (t != L.begin()) { t--; t = L.erase(t); }
			}
			else if (c == '>') { if (t != L.end())t++; }
			else if (c == '<') { if (t != L.begin())t--; }
			else {
				L.insert(t, c);
			}

		}
		if(!L.empty()){for (auto i : L) cout << i ;}
		
		cout << "\n";
	}
}
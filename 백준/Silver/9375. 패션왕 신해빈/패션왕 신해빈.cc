#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n; //의상 가지 수

		unordered_map<string, int> m;
		
		for (int i = 0; i < n; i++) {
			string name, kind;
			cin >> name >> kind;
			m[kind]++;
		}
		int ans = 1;
		for (auto k : m) {
			ans *= (k.second + 1);
		}

		
		cout << ans-1 << "\n";
		
	}

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	unordered_map<string, string> um;

	for (int i = 0; i < N; i++) {
		string site, pwd;
		cin >> site >> pwd;
		um.insert({ site, pwd });
	}

	for (int i = 0; i < M; i++) {
		string find;
		cin >> find;
		cout << um[find] << "\n";
	}
	return 0;
}
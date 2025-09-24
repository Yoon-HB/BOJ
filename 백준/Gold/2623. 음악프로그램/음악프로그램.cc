#include <bits/stdc++.h>
using namespace std;

int N, M;

int deg[1002];
vector<int> adj[1002];

queue<int> q;
vector<int> res;


int main() {
	cin >> N >> M;

	while (M--) {
		int num;
		cin >> num;

		int a;
		cin >> a;
		for (int i = 0; i < num - 1; i++) {
			int b;
			cin >> b;
			adj[a].push_back(b);
			deg[b]++;
			a = b;
		}
	}

	/*for (int i = 1; i <= N; i++) {
		cout << i << ": " << deg[i] << "\n";
	}*/

	for (int i = 1; i <= N; i++) {
		if (deg[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		res.push_back(cur); //가장 먼저 나와야 함. deg가 0이니까 우선순위가 높음

		for (auto nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	if (res.size() != N) {
		cout << 0;
	}
	else {
		for (int i : res) {
			cout << i << "\n";
		}
	}
	return 0;

}

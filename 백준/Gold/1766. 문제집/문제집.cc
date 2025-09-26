#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> adj[32002];
int deg[32002];
vector<int> ans;

int main() {

	int M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 1; i <= N; i++) {
		if (deg[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.top();
		q.pop();
		ans.push_back(cur);

		for (auto nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	for (int x : ans) {
		cout << x << " ";
	}
	return 0;
}
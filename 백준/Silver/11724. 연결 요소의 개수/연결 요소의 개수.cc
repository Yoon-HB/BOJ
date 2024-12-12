#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool vis[1001];

int cnt = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	//방향이 없는 그래프
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}

	for (int i = 1; i <= N; i++) {
		if (vis[i]) continue;
		cnt++;

		queue<int> q;
		q.push(i);
		vis[i] = true;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (auto nxt : adj[cur]) {
				if (vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
			}
		}
	}

	cout << cnt;

	return 0;
}
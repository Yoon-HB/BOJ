#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M;

vector<pair<int, int>> adj[1002];

int bfs(int a, int b) {
	vector<int> dis(N + 1, -1);
	queue<int> q;
	q.push(a);
	dis[a] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (auto nxt : adj[cur]) {
			if (dis[nxt.Y] != -1) continue; //이미 방문
			dis[nxt.Y] = dis[cur] + nxt.X;
			q.push(nxt.Y);
		}
	}
	return dis[b];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });

	}
	

	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << bfs(a, b) << "\n";	
	}

	return 0;
}
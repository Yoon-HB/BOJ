#include <bits/stdc++.h>

using namespace std;

vector<int> adj[502];
int dist[502];

void bfs() {
	fill(dist, dist + 502, -1);
	queue<int> q;

	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto nxt : adj[cur]) {
			if (dist[nxt] != -1 ) continue; // 이미 방문한 정점은 무시
			q.push(nxt);
			dist[nxt] = dist[cur] + 1; // 이전 정점 거리 + 1
		}
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int m;
	cin >> m;

	int ans = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bfs(); //함수 호출도 안하고 있었네... 바보다 진짜


	for (int i = 1; i <= n; i++) {
		if (dist[i] == 2 || dist[i] ==1) ans++;
	}

	cout << ans;

	return 0;
}
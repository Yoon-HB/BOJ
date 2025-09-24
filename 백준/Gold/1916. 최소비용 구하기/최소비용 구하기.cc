#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;


int N, M;
vector<pair<int, int>> adj[1005];
int dis[1005];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	
	cin >> N;
	cin >> M;

	fill(dis, dis + N + 1, 1e9 + 10);


	for (int i = 1; i <= M; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({ w, v });
	}
	int st, et;
	cin >> st >> et;

	dis[st] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ dis[st], st });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (dis[cur.Y] != cur.X) continue;

		for (auto nxt : adj[cur.Y]) {
			if (dis[nxt.Y] <= dis[cur.Y] + nxt.X) continue;
			dis[nxt.Y] = dis[cur.Y] + nxt.X;
			pq.push({ dis[nxt.Y], nxt.Y });
		}
	}
	cout << dis[et];
	return 0;

}
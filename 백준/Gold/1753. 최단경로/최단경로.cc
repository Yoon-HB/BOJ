#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int V, E, K;

vector<pair<int,int>> adj[200005];
int dis[200005];


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	cin >> K;

	fill(dis, dis + V + 1, 1e9+10);
	//거리, 정점
	priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}

	dis[K] = 0;

	pq.push({ dis[K], K });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (dis[cur.Y] != cur.X) continue;
		for (auto nxt : adj[cur.Y]) {
			if (dis[nxt.Y] <= dis[cur.Y] + nxt.X) continue;
			dis[nxt.Y] = dis[cur.Y] + nxt.X;
			pq.push({ dis[nxt.Y],nxt.Y });
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dis[i] == 1e9 + 10) cout << "INF" << "\n";
		else
		{
			cout << dis[i] << "\n";
		}
	}
	return 0;
}
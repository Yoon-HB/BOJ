#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M, X;
vector<pair<int, int>> adj[1002];
vector<pair<int, int>> adj2[1002]; //돌아오는 길

vector<int> dijkstra(vector<pair<int, int>> graph[1002], int st) {

	vector<int> dis(N + 1, 1e9);

	dis[st] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ dis[st], st });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (dis[cur.Y] != cur.X) continue;
		for (auto nxt : graph[cur.Y]) {
			if (dis[nxt.Y] <= dis[cur.Y] + nxt.X) continue;
			dis[nxt.Y] = dis[cur.Y] + nxt.X;

			pq.push({ dis[nxt.Y], nxt.Y });
		}
	}
	
	return dis;

}
int main() {
	cin >> N >> M >> X;

	while (M--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj2[v].push_back({ w, u });
	
	}
	// 돌아오는 길
	vector<int> fromX = dijkstra(adj, X);
	// 가는 길
	vector<int> toX = dijkstra(adj2, X);

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, toX[i] + fromX[i]);
	}

	cout << ans;

	return 0;
}
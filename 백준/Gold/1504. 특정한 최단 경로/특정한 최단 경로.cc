#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
bool falg = true;
int N, E;

vector<pair<int, int>> adj[802];

int ans = 0;


int Dijkstra(int a, int b) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int dis[802] = {};
	fill(dis, dis + N + 1, 1e9 + 10);

	dis[a] = 0;
	pq.push({ 0, a });

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

	if (dis[b] == 1e9 + 10) {

		return -1;
	}
	else return dis[b];
}
int main() {

	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> E;

	

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	int v1, v2;
	cin >> v1 >> v2;

	long long first_v1 = Dijkstra(1, v1) + Dijkstra(v1, v2) + Dijkstra(v2, N);
	long long first_v2 = Dijkstra(1, v2) + Dijkstra(v2, v1) + Dijkstra(v1, N);


	
	if (Dijkstra(1, v1) == -1 || Dijkstra(v1, v2) == -1 || Dijkstra(v2, N) == -1 ||
		Dijkstra(1, v2) == -1 || Dijkstra(v2, v1) == -1 || Dijkstra(v1, N) == -1
		) ans = -1;

	else ans = min(first_v1, first_v2);

	cout << ans;

	return 0;

}
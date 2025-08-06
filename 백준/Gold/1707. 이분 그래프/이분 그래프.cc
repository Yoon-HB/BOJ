#include <bits/stdc++.h>
using namespace std;

vector<int> adj[20005];
int color[20005];

bool bfs(int st) {
	queue<int> q;
	q.push(st);
	color[st] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (auto nxt : adj[cur]) {
			if (color[nxt] == 0) {
				color[nxt] = -color[cur]; //반대 색상 칠하기
				q.push(nxt);
			}
			else if (color[nxt] == color[cur]) {
				return false;
			}
		}
	}
	

	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K;
	cin >> K;
	
	while (K--) {
		int V, E;
		cin >> V >> E;

		//초기화
		for (int i = 1; i <= V; ++i) {
			adj[i].clear();
			color[i] = 0; 
		}

		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bool answer = true;

		for (int i = 1; i <= V; i++) {
			if (color[i] == 0) {
				if (!bfs(i)) {
					answer = false;
					break;
				}
			}
		}
		
		cout << (answer ?  "YES\n" : "NO\n");
	}

	return 0;
}
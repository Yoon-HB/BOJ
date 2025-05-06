#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int vis[100005];
int parent[100005];


int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> q;
	q.push(1); //루트 노드부터 시작
	vis[1] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) {
			if (!vis[nxt]) {
				parent[nxt] = cur;
				vis[nxt] = 1;
				q.push(nxt);
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
	return 0;
}
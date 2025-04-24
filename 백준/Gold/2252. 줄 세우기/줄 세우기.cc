#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> adj[32005];
int deg[32005];

int main() {

	vector<int> result;
	queue<int> q;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;

		adj[A].push_back(B);
		deg[B]++;
	}

	for (int i = 1; i <= N; i++) {
		if (deg[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		result.push_back(cur);

		for (int nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	for (auto i : result) {
		cout << i << ' ';
	}
	return 0;
}
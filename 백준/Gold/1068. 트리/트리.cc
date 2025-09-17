#include <bits/stdc++.h>
using namespace std;

vector<int> adj[52];

int cnt = 0;
int node;

void dfs(int cur) {
	int cnt2 = 0;

	for (int nxt : adj[cur]) {
		if (nxt == node) {
			continue;
		}
		cnt2++;
		dfs(nxt);
	}

	if (cnt2 == 0) cnt++;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	int root = 0;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num == -1) {
			root = i;
			continue;
		}
		adj[num].push_back(i);

	}
	
	cin >> node;

	if (node == root) {
		cout << 0;
		return 0;
	}

	dfs(root);

	cout << cnt;

	return 0;
}
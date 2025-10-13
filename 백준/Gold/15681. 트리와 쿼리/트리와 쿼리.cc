#include <bits/stdc++.h>
using namespace std;


int N, R, Q;

vector<int> adj[100002];
int sub[100002];

int dfs(int cur, int p) {
	sub[cur] = 1;

	for (auto nxt : adj[cur]) {
		if (nxt == p) continue;
		sub[cur] += dfs(nxt, cur);
	}
	return sub[cur];

}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> R >> Q;

	for (int i = 0; i < N-1; i++) {
		int U, V;
		cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);

	}
	dfs(R, -1);

	//정점 U를 루트로 하는 서브트리에 속한 정점의 수를 출력
	for (int i = 0; i < Q; i++) {
		int U;
		cin >> U;
		cout << sub[U] << "\n";
		
	}


	return 0;
}
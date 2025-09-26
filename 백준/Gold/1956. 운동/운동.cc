#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;

int D[402][402];
int main() {

	int V, E;
	cin >> V >> E;


	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) D[i][j] = 0;
			else D[i][j] = INF;
		}
	}


	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		D[a][b] = min(D[a][b], c);
	}

	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (D[i][k] == INF || D[k][j] == INF) continue;
				if (D[i][j] < D[i][k] + D[k][j]) continue;
				D[i][j] = D[i][k] + D[k][j];
			}
		}
	}
	int ans = INF;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			// i와 j가 같으면 사이클이 아님
			if (i == j) continue;
			if (D[i][j] != INF && D[j][i] != INF) {
				ans = min(ans, D[i][j] + D[j][i]);
			}
		}
	}

	if (ans == INF) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}
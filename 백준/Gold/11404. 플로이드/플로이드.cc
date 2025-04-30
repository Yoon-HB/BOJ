#include <bits/stdc++.h>
using namespace std;

int D[102][102];

int n, m;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (D[a][b] == 0 || D[a][b] > c) D[a][b] = c;
		
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k) continue; // 자기 자신으로 가는 경로는 0으로 유지
				if (D[j][i] == 0 || D[i][k] == 0) continue; // 중간 경로가 없으면 갱신 불가

				if (D[j][k] == 0 || D[j][k] > D[j][i] + D[i][k]) {
					D[j][k] = D[j][i] + D[i][k];
				}
				
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
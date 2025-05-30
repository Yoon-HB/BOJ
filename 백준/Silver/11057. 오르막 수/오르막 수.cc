#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	//티이블 점화식 
	int dp[1001][10] = { 0, };

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
			}
		}
	}

	int ans = 0;
	for (int j = 0; j <= 9; j++) {
		ans = (ans + dp[N][j]) % 10007;
	}

	cout << ans;
	return 0;
}
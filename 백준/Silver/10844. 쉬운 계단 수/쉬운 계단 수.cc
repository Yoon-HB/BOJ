#include <bits/stdc++.h>
using namespace std;

long long dp[102][10];

int main() {

	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j > 0) dp[i][j] += dp[i - 1][j - 1];
			if (j < 9) dp[i][j] += dp[i - 1][j + 1];

			dp[i][j] %= 1000000000;
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += dp[n][i];
	}
	ans %= 1000000000;
	cout << ans;
}
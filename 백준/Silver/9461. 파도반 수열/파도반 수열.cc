#include <bits/stdc++.h>
using namespace std;

long long dp[102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	//초기 배열 설정
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	//DP 점화식
	for (int i = 6; i <= 100; i++) {
		dp[i] = dp[i - 5] + dp[i - 1];
	}

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";

	}
}
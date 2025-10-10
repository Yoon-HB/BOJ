#include <bits/stdc++.h>
using namespace std;
int N;

int dp[100002];


int main() {
	cin >> N;
	dp[0] = 0;
	dp[1] = 3;
	dp[2] = 7;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i-1]*2 + dp[i-2])%9901;
	}
	cout << dp[N];

	return 0;
}
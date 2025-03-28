#include <bits/stdc++.h>

using namespace std;

int N, M;

int arr[10005];
int dp[10005];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max({ dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i] });
	}

	cout << dp[n];


	return 0;
}
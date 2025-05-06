#include <bits/stdc++.h>
using namespace std;

int dp[100005];
int arr[100005];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}
	int ans = *max_element(dp+1, dp + n+1);
	cout << ans;
	return 0;
}
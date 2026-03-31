#include <bits/stdc++.h>
using namespace std;

int dp[1002];

int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> box(n, 0); //크기, 초기값 순서

	for (int i = 0; i < n; i++) {
		cin >> box[i];
		dp[i] = 1;
	}


	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (box[j] < box[i]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}

	int ans = *max_element(dp, dp + n);
	cout << ans;

	return 0;
}
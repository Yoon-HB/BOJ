#include <bits/stdc++.h>
using namespace std;
int price[1002];


int main() {
	int N;
	cin >> N;

	for(int i =1; i <= N; i++) {
		cin >> price[i];
	}

	int dp[1002] = { 0, };

	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + price[j]);
		}
	}

	cout << dp[N];

	return 0;
}
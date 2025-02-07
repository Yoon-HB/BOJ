#include <bits/stdc++.h>
using namespace std;

int DP[1000002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;

	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;

	for (int i = 4; i <= N; i++) {
		DP[i] = (DP[i - 2] + DP[i - 1])%15746;
	}

	cout << DP[N];
}
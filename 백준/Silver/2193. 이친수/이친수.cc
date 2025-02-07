#include <bits/stdc++.h>
using namespace std;

long long DP[92];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;

	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 2;

	for (int i = 4; i <= N; i++) {
		DP[i] = (DP[i - 2] + DP[i - 1]);
	}

	cout << DP[N];
}
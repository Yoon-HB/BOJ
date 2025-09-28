#include <bits/stdc++.h>
using namespace std;
int DP[50002];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		DP[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}
    
	cout << DP[n];

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long DP[1000005];

int main() {


	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	for (int i = 4; i <= 1000000; i++) {
		DP[i] = (DP[i - 3]+ DP[i - 2] + DP[i - 1]) % 1000000009;
	}

	int T;
	cin >> T;

	
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << DP[n] << "\n";
	}
}

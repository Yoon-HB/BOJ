#include <bits/stdc++.h>
using namespace std;

int main() {
	
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	for (int i = 2; i * i <= N; i++) {
		while (N % i == 0) {
			cout << i << "\n";
			N = N / i;
		}
	}

	if (N != 1) cout << N;

	return 0;

}
#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;


	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;

		int ans = 0;

		for (int j = 1; j <= n; j++) {
			if (j * j <= n) ans++;
			else break;
		}
		cout << ans << "\n";
	}

}
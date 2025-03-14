#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int num = 1;
	int cnt = 1;

	int i = 1;

	while (N > num) {
		num = num + (6 * i++);
		cnt++;
	}

	cout << cnt;

	return 0;
}
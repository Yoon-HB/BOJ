#include <bits/stdc++.h>
using namespace std;

int N;
int half[101];

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		half[i] = 2 * num;
	}

	for (int i = 1; i < N; i++) {
		int a = gcd(half[0], half[i]);
		cout << half[0] / a << "/" << half[i] / a << "\n";
	}
	return 0;
}
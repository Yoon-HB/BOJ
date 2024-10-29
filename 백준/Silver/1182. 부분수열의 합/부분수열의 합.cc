#include <bits/stdc++.h>
using namespace std;

int arr[30];
int n, s;
int cnt = 0;

void func(int cur, int total) {
	if (cur == n) {
		if (total == s) cnt++;
		return;
	}
	func(cur + 1, total); //현재 수 더하지 않음
	func(cur + 1, total + arr[cur]); //현재 수 더하기
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	func(0, 0);
	if (s == 0) cnt--; // 공집합 제거
	cout << cnt;
	return 0;
}
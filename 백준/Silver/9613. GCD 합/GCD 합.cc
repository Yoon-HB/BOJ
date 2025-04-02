#include <bits/stdc++.h>

using namespace std;


int gcd(int a, int b) { //최대공약수 함수
	if (a == 0) return b;
	return gcd(b % a, a);
}
int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		long long ans = 0;

		int arr[101] = { 0, };

		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}

		for (int j = 0; j < n-1; j++) {  //범위 설정 주의하기!
			for (int k = j+1; k < n; k++) {
				ans += gcd(arr[j], arr[k]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
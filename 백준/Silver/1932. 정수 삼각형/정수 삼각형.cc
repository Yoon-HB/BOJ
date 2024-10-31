#include <bits/stdc++.h>
using namespace std;

int arr[502][502];

int main() {
	int n;
	cin >> n;

	
	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	int dp[502][502];
	dp[0][0] = arr[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + arr[i][j];  // 왼쪽 끝
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];  // 오른쪽 끝
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j]; //상위 2개 중 더 큰 값 선택해서 더하기
		}
	}
	int max_num = 0;

	//dp배열에서 최대값 찾기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			max_num = max(max_num, dp[i][j]);
		}
	}
	cout << max_num;

	return 0;
}
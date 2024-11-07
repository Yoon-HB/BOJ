#include <bits/stdc++.h>

using namespace std;

int t[20];
int p[20];
int dp[20]; //i번째 일에 상담을 *시작했을 때* 얻을 수 있는 최대 수익


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = n; i >= 1; i--) {
		// i번째 일에 상담을 할 수 있을 경우
		if (t[i] + i <= n + 1) {
			//상담을 했을 때와 상담을 하지 않았을 때 얻을 수 있는 수익 중 최대 수익 담기
			dp[i] = max(dp[i + t[i]] + p[i], dp[i + 1]);
		}
		else {
			dp[i] = dp[i + 1];
		}
	}

	//최대값 뽑기
	cout << *max_element(dp, dp + n + 1);
    
    return 0;
	
}


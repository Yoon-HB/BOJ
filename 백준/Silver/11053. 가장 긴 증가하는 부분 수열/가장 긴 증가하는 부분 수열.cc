#include <bits/stdc++.h>
using namespace std;

int A[1001];           // 입력 배열
int dp[1001];          // DP 배열

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        dp[i] = 1; // dp 배열 초기화: 각 숫자만으로도 길이 1
    }

    // 동적 프로그래밍 수행
    for (int i = 2; i <= N; i++) {          // 현재 위치
        for (int j = 1; j < i; j++) {       // 이전 위치들
            if (A[j] < A[i]) {              // 증가 조건
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // dp 배열에서 최댓값 찾기
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
    return 0;
}
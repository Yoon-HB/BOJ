#include <bits/stdc++.h>
using namespace std;

int S[12];
int B[12];
long long min_num = 1e9 + 7;
int N;

void solve(int idx, long long sum_s, long long sum_b, int cnt) {
	if (idx == N) {
		if (cnt > 0) {
			min_num = min(min_num, abs(sum_s - sum_b));
		}
		return;
	}

	//idx번 재료를 사용하지 않는 경우
	solve(idx + 1, sum_s, sum_b, cnt);

	//idx번 재료를 사용하는 경우
	solve(idx + 1, sum_s * S[idx], sum_b + B[idx], cnt + 1); 
}
int main() {
	//신맛 S와 쓴맛 B
	//신맛은 사용한 재료의 신맛의 곱이고, 쓴맛은 합

	cin >> N;

	for(int i =0; i < N; i++) {
		cin >> S[i] >> B[i];
	}

	solve(0, 1, 0, 0);

	cout << min_num; 

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int frd[102][102];
int N, M;


int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			frd[i][j] = (i == j ? 0 : INF);
		}
	}

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		frd[A][B] = 1;
		frd[B][A] = 1; //양방향
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (frd[i][k] == INF || frd[k][j] == INF) continue; //경로 존재하지 않으면 무시
				frd[i][j] = min(frd[i][j], frd[i][k] + frd[k][j]);
			}
		}
	}

	int ans = 0;
	int min_sum = 1e9;

	
	for (int i = 1; i <= N; i++) {
		int sum = 0;

		for (int j = 1; j <= N; j++) {
			sum += frd[i][j];
		}
		// 여러 명일 경우에는 번호가 가장 작은 사람

		if (sum < min_sum) {
			min_sum = sum;
			ans = i;
		} 
	}

	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int N, M;

int arr[8];

void backTracking(int cnt, int st) {
    if (cnt == M) { // M개 다 골랐다면
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = st; i <= N; i++) {
        arr[cnt] = i;
        backTracking(cnt + 1, i);
    }
}
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;

	backTracking(0, 1);


	return 0;
}
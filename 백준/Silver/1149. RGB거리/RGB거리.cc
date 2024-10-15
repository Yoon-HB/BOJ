#include <bits/stdc++.h>
using namespace std;

int d[1005][3];
int r[1005], g[1005], b[1005];
int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}

	//0은 r 1은 g 2는 b
	d[1][0] = r[1];
	d[1][1] = g[1];
	d[1][2] = b[1];

	for (int i = 2; i <= n; i++) {
		//빨간색으로 칠했을 경우
		d[i][0] = min(d[i - 1][1], d[i - 1][2])+ r[i];
		//초록색으로 칠했을 경우
		d[i][1] = min(d[i - 1][0], d[i - 1][2])+ g[i];
		//파란색으로 칠했을 경우
		d[i][2] = min(d[i - 1][1], d[i - 1][0])+ b[i];
		
	}

	cout << min({ d[n][0], d[n][1], d[n][2] });

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, K;
int vis[100005];

int main() {
	cin >> N >> K;

	deque<pair<int, int>> dq;
	dq.push_back({ N, 0 });
	vis[N] = 1;

	while (!dq.empty()) {
		auto cur = dq.front(); dq.pop_front();

		if (cur.X == K) {
			cout << cur.Y << "\n";
			return 0;
		}

		// 순간이동 (0초)
		if (2 * cur.X <= 100000 && !vis[2 * cur.X]) {
			vis[2 * cur.X] = 1;
			dq.push_front({ 2 * cur.X, cur.Y });
		}

		// 걷기 (1초)
		if (cur.X - 1 >= 0 && !vis[cur.X - 1]) {
			vis[cur.X - 1] = 1;
			dq.push_back({ cur.X - 1, cur.Y + 1 });
		}
		if (cur.X + 1 <= 100000 && !vis[cur.X + 1]) {
			vis[cur.X + 1] = 1;
			dq.push_back({ cur.X + 1, cur.Y + 1 });
		}
	}
}

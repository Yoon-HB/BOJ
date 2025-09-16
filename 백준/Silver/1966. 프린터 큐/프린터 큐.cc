#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	//중요도가 같은 문서가 여러 개일 수도 있음

	while (T--) {
		int N, M;
		cin >> N >> M;
		//일반 큐, 우선순위 큐 2개?
		int num = 0;
		queue<pair<int, int>> q;
		priority_queue<int> pq;

		for (int i = 0; i < N; i++) {
			int s;
			cin >> s;
			q.push({ s, i }); //{중요도, 문서}
			pq.push(s);
		}
		int cnt = 0;

		while (!q.empty() && !pq.empty()) {
			auto cur = q.front();
			if (cur.first == pq.top()) {
				if (cur.second == M) {
					cout << cnt + 1 << "\n";
					break;
				}
				q.pop();
				pq.pop();
				cnt++;

			}
			else {
				q.pop();
				q.push(cur);
			}
		}

	}
	return 0;
}
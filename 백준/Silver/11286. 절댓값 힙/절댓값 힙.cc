#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	while (n--) {
		int num;
		cin >> num;

		if (num == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
		else {
			pq.push({ abs(num), num });
		}
	}
	return 0;
}
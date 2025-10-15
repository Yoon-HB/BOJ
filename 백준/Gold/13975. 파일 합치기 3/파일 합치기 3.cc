#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int K;
		cin >> K;
		long long ans = 0;

		priority_queue<long long, vector<long long>, greater<long long>> pq;
		
		for (int i = 0; i < K; i++) {
			long long num;
			cin >> num;
			pq.push(num);
		}

		while (pq.size () > 1) {
			long long a = pq.top();
			pq.pop();

			long long b = pq.top();
			pq.pop();

			long long sum = a + b;
			ans += sum;

			pq.push(sum);
		}
		cout << ans << "\n";
		
	}
}
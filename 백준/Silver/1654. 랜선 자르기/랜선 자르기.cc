#include <bits/stdc++.h>
using namespace std;

int main() {

	cin.sync_with_stdio(0);
	cin.tie(0);

	int K, N;
	cin >> K >> N;

	
	long long answer = 0;

	vector<long long> v(K);

	for (int i = 0; i < K; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	long long low = 1;
	long long high = v.back();

	while (low <= high) {
		long long mid = (low + high) / 2;
		long long sum = 0;

		for (int i = 0; i < v.size(); i++) {
			sum += v[i] / mid;
		}

		if (sum >= N) {
			answer = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << answer;
	return 0;
}
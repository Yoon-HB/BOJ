#include <bits/stdc++.h>

using namespace std;


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> M >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int low = 1;
	int high = v.back();

	int result = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			cnt += v[i] / mid;
		}

		if (cnt >= M) {
			result = mid; 
			low = mid + 1;
		}
		else {
			high = mid - 1; 
		}
	}

	cout << result << "\n";

}
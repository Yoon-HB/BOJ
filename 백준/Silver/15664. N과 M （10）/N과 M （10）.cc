#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int N, M;

vector<int> res;
vector<bool> used(8, false);

void backTracking(int cnt, int st) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}

	int prev = 0;

	for (int i = st; i < arr.size(); i++) {
		
		if (arr[i] != prev) {
			res.push_back(arr[i]);
			backTracking(cnt + 1, i + 1);
			res.pop_back();
		}
		prev = arr[i];
	}
}


int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	backTracking(0, 0);


	return 0;
}
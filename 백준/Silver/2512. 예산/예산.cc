#include <bits/stdc++.h>
using namespace std;
int N;
//총 합계를 계산
vector<int> v;

int calculate(int n) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > n) sum += n;
		else sum += v[i];
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	int money;
	cin >> money;

	int high = v.back();
	int low = 1;
	int answer = 0;

	while (low <= high) {
		int mid = (high + low) / 2;
		if (calculate(mid) > money)
			high = mid - 1;
		else {
			answer = mid;
			low = mid + 1;
		}
		
	}
	cout << answer;
	return 0;
}
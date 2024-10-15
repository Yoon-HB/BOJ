#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	//투포인터
	int st = 0;
	int en = 0;
	int answer = 2000000000;

	int sum = v[0];

	for (st = 0; st < v.size(); st++) {
		while (en < n && sum < m) {
			en++;
			if (en != n) sum += v[en];
		}
		if (en == n) {
			break;
		}

		answer = min(answer, en - st + 1);
		sum = sum - v[st];
	}
	
	if (answer == 2000000000) {
		answer = 0;
	}

	cout << answer;
	return 0;
}
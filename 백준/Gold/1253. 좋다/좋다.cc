#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	vector<int> v;

	for(int i =0; i < N; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	
	int ans = 0;

	for (int i =0; i < v.size(); i++) {
		int st = 0;
		int en = N - 1;

		while (st < en) {
			if (st == i) {
				st++;
				continue;
			}
			if (en == i) {
				en--;
				continue;
			}

			long long sum = v[st] + v[en];

			if (sum == v[i]) {
				ans++;
				break;
			}
			else if (sum > v[i]) en--;
			else st++;
		}
		
	}
	cout << ans;
	return 0;
}
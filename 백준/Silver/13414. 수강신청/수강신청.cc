#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second < b.second;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int  K, L;
	cin >> K >> L;

	unordered_map<string, int> m;

	for (int i = 0; i < L; i++) {
		string num;
		cin >> num;

		m[num] = i;
	}
	vector<pair<string, int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), comp);

	int t = 1;
	for (auto k : v) {
		if (t > K) return 0;
		cout << k.first << "\n";
		t++;
	}
	return 0;
}
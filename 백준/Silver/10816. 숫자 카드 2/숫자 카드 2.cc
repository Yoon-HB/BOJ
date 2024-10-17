#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v1, v2;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v1.push_back(num);
	}
	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		v2.push_back(num);
	}

	sort(v1.begin(), v1.end());

	for (int i = 0; i < v2.size(); i++) {
		cout << upper_bound(v1.begin(), v1.end(), v2[i]) - lower_bound(v1.begin(), v1.end(), v2[i]) << " ";
	}
	return 0;
}
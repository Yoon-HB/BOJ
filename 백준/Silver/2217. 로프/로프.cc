#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int k = n - i;

		int max_weight = v[i] * k;
		if (max_weight >= answer) {
			answer = max_weight;
		}
	}

	cout << answer;
 
	return 0;
}
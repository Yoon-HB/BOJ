#include <bits/stdc++.h>
using namespace std;



int main() {

	while (1) {
		int k;

		cin >> k;
		if (k == 0) break;

		vector<int> n;


		for (int i = 1; i <= k; i++) {
			int num;
			cin >> num;
			n.push_back(num);
		}
		sort(n.begin(), n.end());

		vector<int> v(k, 1); // 크기를 k로 맞춤
		fill(v.begin(), v.begin() + 6, 0); // 6개만 0 (고를 개수)


		do {
			for (int i = 0; i < k; i++) {
				if (v[i] == 0) {
					cout << n[i] << ' ';
				}
			}
			cout << "\n";

		} while (next_permutation(v.begin(), v.end()));

		cout << "\n";
	}
	return 0;
}
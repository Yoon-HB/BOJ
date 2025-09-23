#include <bits/stdc++.h>
using namespace std;

int main(){

	cin.tie(0);
	cin.sync_with_stdio(0);

	string S, E, Q;
	cin >> S >> E >> Q;

	string time, name;

	int ans = 0;

	unordered_map<string, int> um;

	while (cin >> time >> name) {
		if (time <= S) um.insert({ name, 1 });

		if (time <= Q && time >= E) {
			if (um[name] == 1) {
				ans++;
				um[name] = 2;
			}
		}
	}

	cout << ans;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	string s;
	cin >> s;

	unordered_set<string> set;

	for (int i = 0; i < s.length(); i++) {
		string str = "";
		int l = 1;

		for (int j = 1; j <= s.length()-i; j++) {
			str = s.substr(i, j);
			set.insert(str);
		}
	}
	cout << set.size(); 
	return 0;
}
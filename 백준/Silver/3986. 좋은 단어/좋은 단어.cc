#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string str;

	

	for (int i = 0; i < n; i++) {
		cin >> str;

		stack<char> st;
		if (str.length() % 2 == 0) {
			for (int j = 0; j < str.length(); j++) {
				if (st.empty()) st.push(str[j]);
				else {
					char ch = st.top();
					if (ch == str[j]) {
						st.pop();
					}
					else {
						st.push(str[j]);
					}
				}
			}
			if (st.empty()) cnt++;
		}
	}
	cout << cnt;

	return 0;
}
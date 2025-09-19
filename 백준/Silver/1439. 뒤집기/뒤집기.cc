#include <bits/stdc++.h>
using namespace std;

int main() {

	cin.sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;
	

	int cnt = 0;

	char ch = S[0];

	for (int i = 1; i < S.length(); i++) {
		if (S[i] != ch) cnt++;
		ch = S[i];
	}

	if (cnt % 2 == 0) cout << cnt / 2;
	else cout << cnt / 2 + 1;
    
	return 0;
}
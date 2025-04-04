#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string ch;
	cin >> ch;

	sort(ch.begin(), ch.end(), greater<char>());

	int cnt = 0;
	for (int i = 0; i < ch.length(); i++)
		cnt += (ch[i] - '0');

	if (cnt % 3 == 0 && ch.back() == '0')
		cout << ch;
	else
		cout << "-1";

	return 0;
}

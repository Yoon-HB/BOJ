#include <bits/stdc++.h>
using namespace std;

int main() {
	string str, fstr;
	getline(cin, str); //입력에 공백이 있을 수 있음
	getline(cin, fstr);

	int pos = 0, cnt = 0;
	while (1) {
		int res = str.find(fstr, pos);
		if (res == string::npos) break;
		cnt++;
		pos = res + fstr.length();  // 겹치지 않게 이동
	}
	cout << cnt;
}

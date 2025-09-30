#include <bits/stdc++.h>
using namespace std;

int s;
int onoff[102];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> s;


	for (int i = 1;i <= s; i++) {
		cin >> onoff[i];
	}

	int n;
	cin >> n;
	// 남자: 자기가 받은 수의 배수이면, 그 스위치의 상태를 바꾼다
	// 여자 : 좌우 대칭
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		if (a == 1) {		
			for (int j = b; j <= s; j += b) {
				if (onoff[j] == 0) onoff[j] = 1;
				else onoff[j] = 0;

			}
		}
		else {
			onoff[b] = 1 - onoff[b];

			int left = b - 1;
			int right = b + 1;

			while (left >= 1 && right <= s && onoff[left] == onoff[right]) {
				onoff[left] = 1 - onoff[left];
				onoff[right] = 1 - onoff[right];
				left--;
				right++;
			}
	
		}
	}

	for (int i = 1;i <= s; i++) {
		cout << onoff[i] << " ";
        if (i % 20 == 0) {
			cout << "\n";
		}
	}
	return 0;
}
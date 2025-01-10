#include <bits/stdc++.h>
using namespace std;

int main() {

	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int i =0; i < T; i++) {

		int H, W, N;
		cin >> H >> W >> N;

		int front_num = N % H;
		int last_num = N / H;

		if (front_num > 0) {
			last_num += 1;
		}
		else front_num = H;

		cout << front_num * 100 + last_num << "\n";

	}
	return 0;

}
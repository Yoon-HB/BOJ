#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int arr[12] = {0,1, 2, 4 };

	for (int j = 4; j < 12; j++) {
		arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
	}

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		cout << arr[num] << "\n";
	}

	return 0;
}
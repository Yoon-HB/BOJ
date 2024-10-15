#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	
	cin >> n >> m;
	int* arr = new int[n+1];
	int sum[100001] = { 0 };

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
		sum[i] = a + sum[i - 1];
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum [a-1] << "\n";
	}
    return 0;
}


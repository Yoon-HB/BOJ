#include <bits/stdc++.h>
using namespace std;

long long arr[10001];

int main()
{

	int N;
	long long M;
	cin >> N >> M;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		arr[i] = arr[i - 1] + v[i-1];
	}
	for (int i = 1; i <= N; i++) 
		cnt += binary_search(arr, arr + i, arr[i] - M); //true false로 반환 (0, 1)

	cout << cnt;

	return 0;
}
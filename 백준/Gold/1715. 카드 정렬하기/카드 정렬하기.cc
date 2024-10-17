#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<>> pq; //최소 힙

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}
	int answer = 0;
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		answer += a + b;
		pq.push(a+b);
	}
	cout << answer;

	return 0;
}
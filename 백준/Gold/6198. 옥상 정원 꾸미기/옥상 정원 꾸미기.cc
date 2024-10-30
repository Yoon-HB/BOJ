#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; //빌딩의 개수
	cin >> N;

	stack <int> st;
	long long answer = 0;

	for (int i = 0; i < N; i++) {
		long long  h;
		cin >> h;
		while (!st.empty() && st.top() <= h) {
			st.pop();
		}
		answer += st.size();
		st.push(h);
	}

	cout << answer;
	return 0;
	
}


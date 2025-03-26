#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> card, v;


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		card.push_back(n);
	}

	cin >> M;

	for(int i =0; i < M; i++){
		int n;
		cin >> n;
		v.push_back(n);
	}

	sort(card.begin(), card.end());
	
	for (int i = 0; i < M; i++) {
		int ans = binary_search(card.begin(), card.end(), v[i]);

		if (ans) cout << 1 << " ";
		else cout << 0 << " ";
	}

	return 0;
}
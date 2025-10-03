#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
bool vis[10];
vector<int> res;

void dfs(int cnt) {
	if (cnt == M) {
		for (int i : res) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			vis[i] = true;
			res.push_back(v[i]);
			dfs(cnt + 1);
			res.pop_back();
			vis[i] = false;
		}
			

	}
	

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	dfs(0);

	return 0;
	

}
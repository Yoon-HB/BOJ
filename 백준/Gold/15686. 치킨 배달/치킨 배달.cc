#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int city[52][52];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<pair<int, int>> selected;

int N, M;

int min_city_dis = 1e9+10;

void dfs(int idx, int cnt) {
	if (cnt == M) {
		int city_dis = 0;

		for (auto cur_home : home) {
			int min_home_dis = 1e9 + 10;
			for (auto cur_chicken : selected) {
				int dis = abs(cur_home.X - cur_chicken.X) + abs(cur_home.Y - cur_chicken.Y);
				min_home_dis = min(min_home_dis, dis);
			}
			city_dis += min_home_dis;
		}
		min_city_dis = min(min_city_dis, city_dis);
		return;
	}

	for (int i = idx; i < chicken.size(); i++) {
		selected.push_back(chicken[i]);
		dfs(i + 1, cnt + 1);
		selected.pop_back();
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);


	cin >> N >> M; //최대 치킨집 M개
	
				   
	//도시의 치킨 거리는 모든 집의 치킨 거리의 합
	//0은 빈 칸, 1은 집, 2는 치킨집
	int chnum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++){
			cin >> city[i][j];
			if (city[i][j] == 2) chicken.push_back({ i, j });
			else if (city[i][j] == 1) {
				home.push_back({ i, j });
			}
		}
	}
	dfs(0, 0);
	cout << min_city_dis;

	return 0;
	
}
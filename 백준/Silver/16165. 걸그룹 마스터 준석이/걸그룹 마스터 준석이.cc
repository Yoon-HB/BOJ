#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	unordered_map<string, vector<string>> m;

	while (N--) {
		string group;
		int num;
		string name;


		cin >> group;
		cin >> num;

		for (int i = 0; i < num; i++) {
			cin >> name;
			m[group].push_back(name);

		}
        sort(m[group].begin(), m[group].end());
	}
   
    
	while (M--) {
		string quiz;
		int kind;
		cin >> quiz;
		cin >> kind; //퀴즈의 종류가 0일 경우 팀의 이름이 주어지며, 1일 경우 멤버의 이름

		if (kind == 0) {
			for (auto a : m[quiz]) {
				cout << a << "\n";
					
			}
		}
		else {
			for (auto it = m.begin(); it != m.end(); ++it) {
				for (auto& member : it->second) {
					if (member == quiz) {
						cout << it->first << "\n";
						break;
					}
				}
			}

		}
	}
	return 0;
}
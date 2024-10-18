#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;
		multiset<int> ms;  //중복 가능한 이진 검색 트리  -> 이미 정렬되어 있음

		while (k--) {
			char ch;
			cin >> ch;

			if (ch == 'D') {
				int q;
				cin >> q;

				if (ms.empty()) continue;
				if (q == 1)ms.erase(prev(ms.end())); //ms.end()는 마지막 원소의 다음을 가리키기 때문에 prev 필요!!
				else if (q == -1) ms.erase(ms.begin());
			}
			else {
				int q;
				cin >> q;
				ms.insert(q);
			}
		}
		if (ms.empty()) cout << "EMPTY" << "\n";
		else {
			//중복된 값이 있을 수 있기에 하나만 출력하기 위해서
			cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
		}
	}

	return 0;
}
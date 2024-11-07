#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	//우선순위 큐를 이용한 오름차순 정렬
	priority_queue<int, vector<int>, greater<>> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;

			//큐가 비어있거나 크기가 n보다 작으면 원소 삽입
			if (pq.empty() || pq.size() < n) {
				pq.push(num);
			}
			else {
				//입력 받은 수가 큐의 가장 작은 수(top)보다 크면 큐를 pop하고 새로운 원소 삽입 (자동 오름차순 정렬)
				if (pq.top() < num) {
					pq.pop();
					pq.push(num);
				}
			}
		}
	}

	//N번째 큰 원소이므로 pq의 크기는 항상 n이므로 오름차순 큐이기에 top추출
	cout << pq.top();
    
    return 0;
	
}


#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	//정렬
	sort(v.begin(), v.end());

	//투포인터
	int st = 0;
	int en = 0;

	int answer = 2000000000;
	
	while (en < n) {
		int res = v[en] - v[st];

		if (res >= m) {
			answer = min(res, answer);  //최솟값 설정
			if (answer == m) break; //차이가 M이면 제일 작은 경우이므로 탈출
			st++; //st포인터 움직이기 (en 포인터는 그대로) 더 작은 경우를 찾기 위해
		}
		else {
			en++; // m이상이 아니므로 en포인터 움직이기
		}
	}
	
	cout << answer;
	return 0;
}
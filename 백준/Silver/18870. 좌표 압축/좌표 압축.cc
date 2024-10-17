#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v1, v2;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v1.push_back(num);
		//원본
		v2.push_back(num);
	}
	//오름차순 정렬
	sort(v1.begin(), v1.end()); 
	//중복제거
	v1.erase(unique(v1.begin(), v1.end()), v1.end());

	//이분탐색 함수
	for (int i = 0; i < v2.size(); i++) {
		cout << lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin() << " ";
	}
	return 0;
}
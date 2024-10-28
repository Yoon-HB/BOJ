#include <bits/stdc++.h>

using namespace std;
int d[100005];

int solution(int n) {
    int answer = 0;
    d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 1000000007;
	}
    answer = d[n];
    return answer;
}

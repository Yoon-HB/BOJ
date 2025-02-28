#include <bits/stdc++.h>
using namespace std;


// 최대공약수(GCD) 구하기
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // 분모와 분자의 값 계산
    int down = b * d;
    int up = a * d + b * c;

    int g = gcd(up, down);

    // GCD로 나누어서 기약분수로 변환
    up /= g;
    down /= g;

    cout << up << " " << down;
    return 0;
}
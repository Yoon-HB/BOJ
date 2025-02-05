#include <bits/stdc++.h>
using namespace std;
string pocketname[100002];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> um;

    for (int i = 0; i < N; i++) {
        string pocket;
        cin >> pocket;
        um[pocket] = i + 1;  // unordered_map에 이름 -> 번호 저장
        pocketname[i + 1] = pocket;  // 배열에 번호 -> 이름 저장
    }

    for (int i = 0; i < M; i++) {
        string quest;
        cin >> quest;

        // 🔹 quest가 숫자로만 이루어진 경우 -> stoi 변환 후 사용
        if (isdigit(quest[0])) {  
            cout << pocketname[stoi(quest)] << "\n";  // 포켓몬 이름 출력
        } else {
            cout << um[quest] << "\n";  // 포켓몬 번호 출력
        }
    }

    return 0;
}
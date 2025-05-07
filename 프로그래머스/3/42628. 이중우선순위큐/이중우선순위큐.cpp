#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;

    for (string op : operations) {
        if (op[0] == 'I') {
            int num = stoi(op.substr(2));
            ms.insert(num);
        } else if (!ms.empty()) {
            if (op[2] == '1') {
                auto it = prev(ms.end()); // 최대값
                ms.erase(it);
            } else {
                auto it = ms.begin(); // 최소값
                ms.erase(it);
            }
        }
    }

    if (ms.empty()) return {0, 0};
    return { *prev(ms.end()), *ms.begin() };
}

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

bool cmp2(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second; // 재생 횟수가 같으면 인덱스 오름차순
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> order;
    unordered_map<string, vector<pair<int, int>>> um;

    for (int i = 0; i < genres.size(); i++) {
        um[genres[i]].push_back({plays[i], i}); // (재생 횟수, 인덱스)
        order[genres[i]] += plays[i]; // 장르별 총 재생 횟수
    }

    vector<pair<string, int>> v(order.begin(), order.end());
    sort(v.begin(), v.end(), cmp); // 장르별 총 재생 횟수 기준 정렬

    for (auto& i : v) {
        string genre = i.first;
        sort(um[genre].begin(), um[genre].end(), cmp2); // 장르 내 노래 정렬 (재생 횟수, 인덱스)

        for (int j = 0; j < um[genre].size() && j < 2; j++) { // 최대 2곡 선택
            answer.push_back(um[genre][j].second);
        }
    }

    return answer;
}

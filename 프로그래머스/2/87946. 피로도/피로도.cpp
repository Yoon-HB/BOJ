#include <string>
#include <vector>
#include <iostream>
using namespace std;
//코드 참조해서 풀이.....
//최소 필요 피로도", "소모 피로도"
//완전탐색 -> 방문여부 -> visited배열
int visited[9]={0,};
int res = 0; //최대 던전 탐험 수
//cnt 현재 던전 탐험 수
int dfs(int cnt, int k, vector<vector<int>> dungeons){
    if(cnt>res) res = cnt;
    for(int i  =0; i < dungeons.size(); i++){
        //방문하지 않은 던전
        if(dungeons[i][0] <= k && visited[i] == 0){
            visited[i] = 1; //방문으로 바뀜
            //다시 돌기
            dfs(cnt+1,k-dungeons[i][1], dungeons);
            visited[i] = 0;
        }
    }
    return 0;
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);
    return res;
}
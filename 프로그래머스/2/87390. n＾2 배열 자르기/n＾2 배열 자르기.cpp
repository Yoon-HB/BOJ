#include <string>
#include <vector>

using namespace std;
//배열의 값은 (x,y)에서 x와 y 중 큰 값
//시간초과 주의
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long x, y;
    // 0 1 2 3 4 5
    // 1 1 2 3 4 5
    // 2 2 2 3 4 5
    // 3 3 3 3 4 5
    // 4 4 4 4 4 5
    // 5 5 5 5 5 5

    // x는 i로 나눈 몫에 +1
     //y는 i로 나눈 나머지에 +1
    
    for(long long i = left; i<= right; i++){
        x = i/n + 1;
        y = i%n + 1;
        long long num = x > y ? x : y;
        answer.push_back(num);
    }
    return answer;
}
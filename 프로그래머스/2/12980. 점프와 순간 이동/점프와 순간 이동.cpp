#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 1;
    
    //5000 -> 2500 -> 1250 625(1) 624 312 156 78 39(1) 38 19(1) 18 9 (1) 8 4 2 1(1)
    while(n > 1){
        int div = n%2;
        if(div == 1){
            ans++;
            n = (n-1)/2;   
        }
        else{
            n = n/2;
        }
    }
    return ans;
}
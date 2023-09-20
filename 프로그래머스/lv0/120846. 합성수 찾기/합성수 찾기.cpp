#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int dp[100] = { 0, };
    
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            dp[j-1]++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (dp[i] >= 2) {
            answer++;
        }
    }
    
    return answer;
}
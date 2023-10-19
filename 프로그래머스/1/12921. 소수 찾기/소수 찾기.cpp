#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> dp(n, 0);
    
    dp[0] = 9;
    
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j += (i + 1)) {
            dp[j]++;
        }
    }
    
    sort(dp.begin(), dp.end());
    
    for (int i = 0; i < n; i++) {
        if (dp[i] != 1) {
            answer = i;
            break;
        }
    }
    
    return answer;
}
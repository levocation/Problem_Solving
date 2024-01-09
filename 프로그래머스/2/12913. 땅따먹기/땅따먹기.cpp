#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    const int land_depth = (int)(land.size());
    
    vector<vector<int>> dp(land_depth + 1, vector<int>(4, 0));
    
    for (int i = 1; i <= land_depth; i++) {
        dp[i][0] = max(max(dp[i-1][1], dp[i-1][2]), dp[i-1][3]) + land[i-1][0];
        dp[i][1] = max(max(dp[i-1][0], dp[i-1][2]), dp[i-1][3]) + land[i-1][1];
        dp[i][2] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][3]) + land[i-1][2];
        dp[i][3] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + land[i-1][3];
    }
    
    return *max_element(dp[land_depth].begin(), dp[land_depth].end());
}
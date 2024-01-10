#include <iostream>
#include <vector>

#define MOD 1000000000

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(10));
    for (int num = 0; num < 10; num++) dp[1][num] = (num != 0);
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][1];
        for (int j = 1; j <= 8; j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
        dp[i][9] = dp[i-1][8];
    }
    
    long long sum = 0;
    for (int num = 0; num < 10; num++) {
        sum = (sum + dp[n][num]) % MOD;
    }
    
    cout << sum;
    
    return 0;
}
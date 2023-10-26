#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int num = 0;
    
    cin >> num;
    
    int dp[1001] = {0,};
    
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= num; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    cout << dp[num];
    return 0;
}
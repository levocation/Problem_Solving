#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    int num = 0;
    
    vector<int> v;
    cin >> num;
    
    vector<int> dp(num + 1, 0);
    dp[1] = 0;
    for (int i = 2; i <= num; i++) {
        dp[i] = dp[i-1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }
    
    cout << dp[num];
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int count = 0;
    
    scanf("%d", &count);
    vector<int> v(count, 0);
    
    for (int i = 0; i < count; i++) {
        scanf("%d", &(v[i]));
    }
    
    vector<int> sorted_v = v;
    
    sort(sorted_v.begin(), sorted_v.end(), greater<int>());
    
    long long* dp = new long long[sorted_v[0] + 1];
    
    for (int i = 0; i < sorted_v[0] + 1; i++) {
        if (i == 0) dp[i] = 1;
        else if (i == 1) dp[i] = 1;
        else if (i == 2) dp[i] = 2;
        else if (i == 3) dp[i] = 4;
        else dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
    }
    
    for (int i = 0; i < count; i++) {
        cout << dp[v[i]] << "\n";
    }
}
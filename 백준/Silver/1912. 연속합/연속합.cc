#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int len;
    int max_num = -2147483648;
    
    cin >> len;
    
    vector<int> arr(len);
    
    for (int i = 0; i < len; i++)
        cin >> arr[i];
       
    vector<int> dp(len, 0);
    dp[0] = arr[0];
    max_num = max(dp[0], max_num);
    
    for (int i = 1; i < len; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        max_num = max(dp[i], max_num);
    }
    
    cout << max_num;
    
    return 0;
}
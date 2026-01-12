#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0, answer = 0;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> dp(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dp[i][1] = v[i];
            dp[i][2] = v[i];
        } else if (i == 1) {
            dp[i][1] = v[i];
            dp[i][2] = dp[i-1][1] + v[i];
        } else if (i == 2) {
            dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + v[i];
            dp[i][2] = dp[i-1][1] + v[i];
        } else {
            dp[i][1] = max(max(dp[i-2][1], dp[i-2][2]), max(dp[i-3][1], dp[i-3][2])) + v[i];
            dp[i][2] = dp[i-1][1] + v[i];
        }

        //cout << dp[i][1] << ", " << dp[i][2] << "\n";

        answer = max(answer, max(dp[i][1], dp[i][2]));
    }

    cout << answer;
    
    return 0;
}
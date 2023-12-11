#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int arr[n][3] = {0,};
    int dp[n + 1][3] = {0,};
    int tmp[3] = {0,};
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        arr[i][0] += min(arr[i-1][1], arr[i-1][2]);
        arr[i][1] += min(arr[i-1][0], arr[i-1][2]);
        arr[i][2] += min(arr[i-1][0], arr[i-1][1]);
    }
    
    cout << min(min(arr[n][0], arr[n][1]), arr[n][2]);
    
    return 0;
}
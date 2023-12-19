#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, ans = 2147483647;
    cin >> n;
    
    int arr[n][2] = {0,};
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    
    for (int i = 1; i < (1 << n); i++) {
        // 0부터 (1 << n) 이전까지 반복
        // n이 2라면, 0부터 4(100) 이전값인 3(11)까지 반복
        int a = 1, b = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                a *= arr[j][0];
                b += arr[j][1];
            }
        }
        ans = (abs(a-b) > ans ? ans : abs(a-b));
    }
    cout << ans;
    return 0;
}
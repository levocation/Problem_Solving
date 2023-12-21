#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, ans = 2147483647, st = 0, en = 0;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr, arr + n);
    
    while (en <= n && st <= en) {
        int val = arr[en] - arr[st];
        if (val >= m) {
            if (val < ans) ans = val;
            st++;
        } else {
            en++;
        }
    }
    
    cout << ans;
    
    return 0;
}
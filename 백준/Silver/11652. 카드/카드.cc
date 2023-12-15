#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, cnt = 1, mx = 0;
    cin >> n;
    long long ans = 0;
    long long arr[n] = {0,};
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr, arr + n);
    ans = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) cnt++;
        else {
            if (cnt > mx) {
                mx = cnt;
                ans = arr[i-1];
            }
            cnt = 1;
        }
    }
    
    if (cnt > mx) {
        ans = arr[n-1];
    }
    
    cout << ans;
    
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int st = 0, en = 0, sum = arr[0], ans = 0;
    while (true) {
        if (sum <= m) {
            if (sum == m) ans++;
            en++;
            if (en >= n) break;
            sum += arr[en];
        } else {
            sum -= arr[st];
            st++;
            if (st > en) {
                en = st;
                sum = arr[en];
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
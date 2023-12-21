#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int sum = arr[0], st = 0, en = 0, ans = 2147483647;
    
    while (st <= en) {
        if (sum >= s) {
            if (en - st + 1 < ans) ans = en - st + 1;
            sum -= arr[st];
            st++;
        } else {
            en++;
            if (en >= n) break;
            sum += arr[en];
        }
    }
    
    cout << (ans == 2147483647 ? 0 : ans);
    
    return 0;
}
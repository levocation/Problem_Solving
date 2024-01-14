#include <iostream>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int st = 1, en = 1, ans = 1, n, cnt = 0;
    cin >> n;
    
    while (ans >= 0 && en <= 10000000) {
        if (ans <= n) {
            if (ans == n) cnt++;
            en++;
            ans += en;
        } else {
            ans -= st;
            st++;
        }
    }
    
    cout << cnt;
    
    return 0;
}
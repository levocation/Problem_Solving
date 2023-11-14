#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, ans = 0;
    cin >> n;
    ans = n;
    
    while (n--) {
        cin >> m;
        
        if (m == 1) {
            ans--;
            continue;
        }
        for (int i = 2; i * i <= m; i++) {
            if (!(m % i)) {
                ans--;
                break;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
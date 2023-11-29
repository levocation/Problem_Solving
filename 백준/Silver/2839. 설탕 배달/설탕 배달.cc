#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, ans = 0;
    cin >> n;
    
    ans += (n / 5);
    n = n % 5;
    
    if (n % 3 == 0) {
        ans += (n / 3);
    } else {
        while (n > 0) {
            ans--;
            if (ans < 0) break;
            n += 5;
            if (n % 3 == 0) {
                ans += n / 3;
                break;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 5, tmp, ans = 0;
    while (n--) {
        cin >> tmp;
        ans += (tmp * tmp) % 10;
    }
    
    cout << ans % 10;
    
    return 0;
}
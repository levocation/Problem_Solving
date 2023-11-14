#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, c, i, j = 0, ans = 0;
    cin >> n >> c;
    
    for (i = 1; i <= n; i++) {
        if (!(n % i)) j++;
        if (j == c) {
            ans = i;
            break;
        }
    }
    
    cout << ans;
    
    return 0;
}
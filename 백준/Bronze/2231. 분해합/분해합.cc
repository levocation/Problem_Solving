#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, ans = 0, tmp, sum;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        sum = i;
        tmp = i;
        while (tmp != 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == n) {
            ans = i;
            break;
        }
    }
    
    cout << ans;
    
    return 0;
}
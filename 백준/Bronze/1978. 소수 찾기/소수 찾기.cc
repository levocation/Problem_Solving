#include <iostream>

using namespace std;

int isprime(int n) {
    if (n == 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, t, s = 0, ans = 0;
    cin >> n;
    
    while (n--) {
        cin >> t;
        ans += isprime(t);
    }
    
    cout << ans;
    
    return 0;
}
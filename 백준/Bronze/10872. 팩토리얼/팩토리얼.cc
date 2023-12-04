#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a = 1;
    cin >> n;
    if (n == 0) cout << 1;
    else {
        for (int i = 1; i <= n; i++) {
            a *= i;
        }
        cout << a;
    }
    
    
    return 0;
}
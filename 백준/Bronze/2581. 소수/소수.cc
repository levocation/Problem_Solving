#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n, sum = 0, min = -1;
    bool isSosu = true;
    cin >> m >> n;
    
    for (int i = m; i <= n; i++) {
        isSosu = true;
        if (i == 1) {
            continue;
        }
        for (int j = 2; j * j <= i; j++) {
            if (!(i % j)) {
                isSosu = false;
                break;
            }
        }
        if (isSosu) {
            sum += i;
            if (min == -1) {
                min = i;
            }
        }
    }
    
    if (sum == 0) {
        cout << -1;
    } else {
        cout << sum << '\n' << min;
    }
    
    return 0;
}
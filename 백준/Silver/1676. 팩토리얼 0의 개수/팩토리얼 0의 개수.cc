#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, e = 0, o = 0, tmp, ans = 0;
    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        tmp = i;
        while (tmp % 2 == 0 && tmp != 0) {
            tmp /= 2;
            e++;
        }
        while (tmp % 5 == 0 && tmp != 0) {
            tmp /= 5;
            o++;
        }
    }
    
    cout << min(e, o);
    
    return 0;
}
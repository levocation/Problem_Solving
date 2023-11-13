#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    m = 2;
    for (int i = 0; i < n; i++) {
        m = 2 * m - 1;
    }
    
    cout << m * m;
    
    return 0;
}
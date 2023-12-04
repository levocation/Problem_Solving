#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, mx = -1, mn = 999999, t;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t > mx) mx = t;
        if (t < mn) mn = t;
    }
    
    cout << mx * mn;
    
    return 0;
}
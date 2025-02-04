#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll a, b;

    int factorial[11] = {0, };
    factorial[0] = 1;
    factorial[1] = 1;
    
    for (int i = 2; i <= 10; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    cin >> a >> b;

    cout << factorial[a] / (factorial[a - b] * factorial[b]);
    
    return 0;
}
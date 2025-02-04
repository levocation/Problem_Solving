#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll powerful(int n) {
    ll val = 1;
    for (int i = 0; i < n; i++) {
        val = (val * 31) % 1234567891;
    }

    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll res = 0;
    int len; 
    string input;

    cin >> len >> input;

    for (int i = 0; i < len; i++) {
        res += (input[i] - 'a' + 1) * powerful(i);
    }

    cout << res % 1234567891;
    
    return 0;
}
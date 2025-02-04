#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll res = 0;
    int len; 
    string input;

    cin >> len >> input;

    for (int i = 0; i < len; i++) {
        res += (input[i] - 'a' + 1) * (ll)(pow(31, i));
    }

    cout << res % 1234567891;
    
    return 0;
}
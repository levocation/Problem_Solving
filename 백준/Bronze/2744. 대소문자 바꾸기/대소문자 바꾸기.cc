#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;

    cin >> s;

    for (char& c : s) {
        if (c >= 'a') c -= 32;
        else c += 32;
    }

    cout << s;

    return 0;
}
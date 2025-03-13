#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string a, b, c, res = "";
    int target = 0;

    cin >> a >> b >> c;

    if (a[0] >= '0' && a[0] <= '9') target = stoi(a) + 3;
    else if (b[0] >= '0' && b[0] <= '9') target = stoi(b) + 2;
    else if (c[0] >= '0' && c[0] <= '9') target = stoi(c) + 1;

    if (target % 3 == 0) res += "Fizz";
    if (target % 5 == 0) res += "Buzz";

    if (res == "") cout << target;
    else cout << res;
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int mem_cnt;
    int s, m, l, xl, xxl, xxxl;
    int t, p;

    cin >> mem_cnt;
    cin >> s >> m >> l >> xl >> xxl >> xxxl;
    cin >> t >> p;

    s = (s / t) + (s % t != 0);
    m = (m / t) + (m % t != 0);
    l = (l / t) + (l % t != 0);
    xl = (xl / t) + (xl % t != 0);
    xxl = (xxl / t) + (xxl % t != 0);
    xxxl = (xxxl / t) + (xxxl % t != 0);

    cout << s + m + l + xl + xxl + xxxl << '\n';
    cout << (mem_cnt / p) << ' ' << (mem_cnt % p);
    
    return 0;
}
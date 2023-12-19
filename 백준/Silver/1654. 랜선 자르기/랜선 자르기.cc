#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;

ll k, n, ans;
vector<ll> v(k);

ll cutting(ll x) {
    ll sum = 0;
    for (int len : v) {
        sum += len / x;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> n;
    v = vector<ll>(k);
    for (ll i = 0; i < k; i++) cin >> v[i];
    
    ll st = 1, en = (1 << 31) - 1;
    
    while (st < en) {
        ll mid = (st + en + 1) / 2;
        if (cutting(mid) >= n) st = mid;
        else en = mid - 1;
    }
    
    cout << st;
    
    return 0;
}
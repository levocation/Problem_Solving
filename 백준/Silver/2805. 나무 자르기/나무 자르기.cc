#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;

int n, m;
vector<int> v;


ll get_wood_sum(int x) {
    ll sum = 0;
    for (int len : v) {
        sum += (len > x ? len - x : 0);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    v = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    ll st = 0, en = 1000000000;
    
    while (st < en) {
        ll mid = (st + en + 1) / 2;
        if (get_wood_sum(mid) >= m) st = mid;
        else en = mid - 1;
    }
    
    cout << st;
    
    return 0;
}
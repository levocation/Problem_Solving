#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

vector<ll> arr;
vector<ll> tree;

ll h, s; // height, size

void init(ll idx, ll st, ll en) {
    if (st == en) {
        tree[idx] = arr[st];
    } else {
        ll mid = (st + en) / 2;
        init(idx * 2, st, mid);
        init(idx * 2 + 1, mid + 1, en);
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}

ll query(ll idx, ll st, ll en, ll l, ll r) {
    if (r < st || l > en) return 0;
    if (l <= st && en <= r) return tree[idx];
    
    ll mid = (st + en) / 2;
    return query(idx * 2, st, mid, l, r) + query(idx * 2 + 1, mid + 1, en, l, r);
}

void update(ll idx, ll st, ll en, ll change_idx, ll val) {
    if (change_idx < st || change_idx > en) return;
    if (st == en) {
        arr[change_idx] = val;
        tree[idx] = val;
        return;
    }
    ll mid = (st + en) / 2;
    update(idx * 2, st, mid, change_idx, val);
    update(idx * 2 + 1, mid + 1, en, change_idx, val);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m, k, a, b, c;
    cin >> n >> m >> k;
    
    arr = vector<ll>(n);
    h = (int)ceil(log2(n));
    s = (1 << (h + 1));
    tree = vector<ll>(s, 0);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    init(1, 0, n - 1);
    
    //for (int i = 0; i < s; i++) cout << i << " : " << tree[i] << '\n';
    //cout << "====================\n";
    
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) { // update
            update(1, 0, n - 1, b - 1, c);
            //for (int i = 0; i < s; i++) cout << i << " : " << tree[i] << '\n';
            //cout << "====================\n";
        } else { // sum
            cout << query(1, 0, n - 1, b - 1, c - 1) << '\n';
        }
    }
    
    return 0;
}
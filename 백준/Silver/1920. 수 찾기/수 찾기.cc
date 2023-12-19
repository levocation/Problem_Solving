#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m, tmp;
    vector<ll> na;
    vector<ll> ma;
    
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> tmp;
        na.push_back(tmp);
    }
    cin >> m;
    for (ll i = 0; i < m; i++) {
        cin >> tmp;
        ma.push_back(tmp);
    }
    
    sort(na.begin(), na.end());
    
    for (ll i = 0; i < m; i++) {
        ll st = 0, en = (int)(na.size()) - 1;
        
        while (true) {
            ll mid = (st + en) / 2;
            if (na[mid] == ma[i]) {
                cout << "1\n";
                break;
            } else if (st > en) {
                cout << "0\n";
                break;
            }
            if (na[mid] > ma[i]) en = mid - 1;
            else st = mid + 1;
        }
    }
    
    return 0;
}
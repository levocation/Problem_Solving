#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll num, target, answer = -1;
    pair<ll, ll> p;
    cin >> num >> target;

    queue<pair<ll, ll>> q;

    q.push({num, 1});
    while (!q.empty()) {
        p = q.front(); q.pop();
        
        if (p.first == target) {
            answer = p.second;
            break;
        }
        
        if (p.first * 2 <= target) {
            q.push({p.first * 2, p.second + 1});;
        }
        if (p.first * 10 + 1 <= target) {
            q.push({p.first * 10 + 1, p.second + 1});
        }
    }

    cout << answer;
    
    return 0;
}
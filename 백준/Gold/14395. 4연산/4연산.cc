#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>
#include <vector>

#define X first
#define Y second

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll num, target;
    string ans = "";
    cin >> num >> target;
    
    if (num == target) {
        cout << 0;
        return 0;
    }
    
    queue<pair<ll, string>> q; // pair<현재값, 계산수식>
    set<ll> s;
    
    q.push({num, ""});
    s.insert(num);
    pair<ll, string> cur;
    
    while (!q.empty()) {
        cur = q.front(); q.pop();
        if (cur.X == target) {
            ans = cur.Y;
            break;
        }
        
        if (cur.X * cur.X <= target && s.insert(cur.X * cur.X).Y) {
            q.push({cur.X * cur.X, cur.Y + "*"});
        }
        if (cur.X + cur.X <= target && s.insert(cur.X + cur.X).Y) {
            q.push({cur.X + cur.X, cur.Y + "+"});
        }
        if (s.insert(0).Y) {
            q.push({0, cur.Y + "-"});
        }
        if (cur.X == 0) continue;
        if (s.insert(1).Y) {
            q.push({1, cur.Y + "/"});
        }
    }
    
    if (ans == "") {
        cout << -1;
    } else {
        cout << ans;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x, y, mx, min_dist = 999999;
    cin >> n;
    
    vector<int> adj[n + 1];
    vector<int> vst(n + 1);
    vector<int> min_idx(n + 1, 0);
    queue<int> q;
    int cur;
    
    while (true) {
        cin >> x >> y;
        if (x == -1 && y == -1) break;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for (int i = 1; i <= n; i++) {
        fill(vst.begin(), vst.end(), 0);
        vst[i] = 1;
        mx = 1;
        q.push(i);
        
        while (!q.empty()) {
            cur = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                if (vst[nxt] != 0) continue;
                vst[nxt] = vst[cur] + 1;
                if (vst[nxt] > mx) mx = vst[nxt];
                q.push(nxt);
            }
        }
        if (mx < min_dist) {
            min_dist = mx;
            min_idx.clear();
            min_idx.push_back(i);
        } else if (mx == min_dist) {
            min_idx.push_back(i);
        }
    }
    
    sort(min_idx.begin(), min_idx.end());
    
    cout << min_dist - 1 << ' ' << min_idx.size() << '\n';
    for (int i : min_idx) {
        cout << i << ' ';
    }
    
    return 0;
}
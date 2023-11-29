#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, x, y, ans = 0;
    cin >> n >> m;
    
    vector<int> adj[n + 1];
    vector<int> vst(n + 1, 0);
    
    while (m--) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    queue<int> q;
    int cur;
    
    for (int i = 1; i <= n; i++) {
        if (vst[i]) continue;
        vst[i] = 1;
        q.push(i);
        
        while (!q.empty()) {
            cur = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                if (vst[nxt]) continue;
                vst[nxt] = 1;
                q.push(nxt);
            }
        }
        ans++;
    }
    
    cout << ans;
    
    return 0;
}
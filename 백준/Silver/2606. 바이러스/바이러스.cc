#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, x, y, ans = 0;
    cin >> n >> m;
    
    vector<int> adj[n + 1];
    vector<int> vst(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vst[1] = 1;
    queue<int> q;
    int cur;
    q.push(1);
    
    while (!q.empty()) {
        cur = q.front(); q.pop();
        for (int nxt : adj[cur]) {
            if (vst[nxt] == 1) continue;
            vst[nxt] = 1;
            q.push(nxt);
            ans++;
        }
    }
    
    cout << ans;
    
    return 0;
}
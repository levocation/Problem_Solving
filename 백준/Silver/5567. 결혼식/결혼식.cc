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
    vector<int> dist(n + 1, -1);
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    queue<int> q;
    int cur;
    q.push(1);
    dist[1] = 0;
    
    while (!q.empty()) {
        if (dist[cur] > 2) break;
        cur = q.front(); q.pop();
        for (int nxt : adj[cur]) {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        if (dist[nxt] > 2) break;
            ans++;
        }
    }
    
    cout << ans;
    
    return 0;
}
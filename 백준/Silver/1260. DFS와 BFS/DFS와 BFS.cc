#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, v, x, y;
    cin >> n >> m >> v;
    
    vector<int> adj[n + 1];
    vector<int> bfs(n + 1, 0);
    vector<int> dfs(n + 1, 0);
    
    while (m--) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    queue<int> q;
    vector<int> s;
    int cur;
    
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }
    
    s.push_back(v);
    while (!s.empty()) {
        cur = s.back(); s.pop_back();
        if (dfs[cur] == 1) continue;
        cout << cur << ' ';
        dfs[cur] = 1;
        for (int nxt : adj[cur]) {
            if (dfs[nxt] == 1) continue;
            s.push_back(nxt);
        }
    }
    cout << '\n';
    
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    q.push(v);
    bfs[v] = 1;
    while (!q.empty()) {
        cur = q.front(); q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]) {
            if (bfs[nxt] == 1) continue;
            bfs[nxt] = 1;
            q.push(nxt);
        }
    }
    cout << '\n';
    
    return 0;
}
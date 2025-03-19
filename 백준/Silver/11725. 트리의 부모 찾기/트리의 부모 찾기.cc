#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a, b;
    cin >> n;

    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> p(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int nxt : adj[cur]) {
            if (p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }
    
    for (int i = 2; i < n + 1; i++) {
        cout << p[i] << '\n';
    }
    
    return 0;
}
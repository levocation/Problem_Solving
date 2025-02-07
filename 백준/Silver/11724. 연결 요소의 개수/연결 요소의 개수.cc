#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e, cnt = 0;
    cin >> v >> e;

    vector<vector<int>> graph(v + 1, vector<int>(v + 1, 0));
    vector<int> vis(v + 1, 0);

    for (int i = 0; i < e; i++) {
        int st, en;
        cin >> st >> en;
        graph[st][en] = 1;
        graph[en][st] = 1;
    }

    queue<int> q;

    for (int i = 1; i <= v; i++) {
        if (vis[i]) continue;
        cnt++;
        q.push(i);
        vis[i] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nxt = 1; nxt <= v; nxt++) {
                if (graph[cur][nxt] && !vis[nxt]) {
                    q.push(nxt);
                    vis[nxt] = true;
                }
            }
        }
    }

    cout << cnt;
    
    return 0;
}
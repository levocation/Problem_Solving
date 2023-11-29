#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, mx = 0;
    
    int len = edge.size();
    
    vector<int> adj[n + 1];
    vector<int> dist(n + 1, -1);
    dist[1] = 0;
    
    queue<int> q;
    int cur, max_idx = -1, cnt = 0;
    
    for (vector<int> e : edge) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    q.push(1);
    
    while (!q.empty()) {
        cur = q.front(); q.pop();
        
        for (int nxt : adj[cur]) {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            if (dist[nxt] > mx) {
                mx = dist[nxt];
                answer = 1;
            } else if (dist[nxt] == mx) {
                answer++;
            }
            q.push(nxt);
        }
    }
    
    return answer;
}
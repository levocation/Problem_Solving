#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string tmp = "";
    pair<string, int> cur = {"---------", 0};
    int x, y, zero_pos, nx, ny;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cur.first[i * 3 + j];
        }
    }
    
    set<string> s;
    queue<pair<string, int>> q;
    q.push(cur);
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    while (!q.empty()) {
        cur = q.front(); q.pop();
        if (cur.first == "123456780") {
            cout << cur.second;
            return 0;
        }
        zero_pos = cur.first.find('0');
        x = zero_pos / 3;
        y = zero_pos % 3;
        
        for (int dir = 0; dir < 4; dir++) {
            nx = x + dx[dir];
            ny = y + dy[dir];
            
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            tmp = cur.first;
            swap(tmp[nx * 3 + ny], tmp[zero_pos]);
            if (s.insert(tmp).second) q.push({tmp, cur.second + 1});
        }
    }
    
    cout << -1;
    
    return 0;
}
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, ans = 100000;
    string tmp;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> vst(n, vector<int>(n, 100000));
    vst[0][0] = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            board[i][j] = !((char)tmp[j] - '0');
            // 흰방을 0, 검은방을 1로 수정
        }
    }
    
    queue<pair<int, int>> q;
    pair<int, int> cur;
    q.push({0, 0});
    
    int nx, ny;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (!q.empty()) {
        cur = q.front(); q.pop();
        if (cur.X == n-1 && cur.Y == n-1) {
            ans = min(vst[n-1][n-1], ans);
        }
        
        for (int dir = 0; dir < 4; dir++) {
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vst[cur.X][cur.Y] + board[nx][ny] >= vst[nx][ny]) continue;
            
            vst[nx][ny] = vst[cur.X][cur.Y] + board[nx][ny];
            q.push({nx, ny});
        }
    }
    
    cout << ans;
    
    return 0;
}
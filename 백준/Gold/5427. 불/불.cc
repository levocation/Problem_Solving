#include <iostream>
#include <queue>
#include <string>
#include <utility>

#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, m;
    bool correct = false;
    
    int nx, ny;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    string tmp;
    queue<pair<int, int>> q;
    pair<int, int> cur;
    cin >> t;
    while (t--) {
        q = queue<pair<int, int>>();
        cin >> m >> n;
        int board[n][m];
        for (int i = 0; i < n; i++) fill(board[i], board[i] + m, 0);
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            for (int j = 0; j < m; j++) {
                if (tmp[j] == '#') {
                    board[i][j] = -1;
                } else if (tmp[j] == '@') {
                    cur = {i, j};
                    board[i][j] = 1;
                } else if (tmp[j] == '*') {
                    board[i][j] = -2;
                    q.push({i, j});
                }
            }
        }
        q.push(cur);
        correct = false;
        
        while (!q.empty()) {
            cur = q.front(); q.pop();
            
            if ((cur.X == 0 || cur.X == n - 1 || cur.Y == 0 || cur.Y == m - 1) 
            && board[cur.X][cur.Y] > 0) {
                cout << board[cur.X][cur.Y] << '\n';
                correct = true;
                break;
            }
            
            for (int dir = 0; dir < 4; dir++) {
                nx = cur.X + dx[dir];
                ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (board[nx][ny] != 0) continue;
                
                if (board[cur.X][cur.Y] == -2) {
                    board[nx][ny] = -2;
                } else if (board[cur.X][cur.Y] > 0) {
                    board[nx][ny] = board[cur.X][cur.Y] + 1;
                }
                q.push({nx, ny});
            }
        }
        if (!correct) {
            cout << "IMPOSSIBLE\n";
        }
    }
    
    return 0;
}
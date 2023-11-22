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
    
    int n, m, count = 0, tcount, max = 0;
    cin >> m >> n;
    tcount = n * m;
    
    int board[n][m];
    queue<pair<int, int>> q;
    pair<int, int> cursor;
    
    string tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                q.push({i, j});
                tcount--;
            } else if (board[i][j] == -1) {
                tcount--;
            }
        }
    }
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int nx, ny;
    
    while (!q.empty()) {
        cursor = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            nx = cursor.X + dx[dir];
            ny = cursor.Y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] != 0) continue;
            board[nx][ny] = board[cursor.X][cursor.Y] + 1;
            q.push({nx, ny});
            count++;
            if (board[nx][ny] - 1 > max) max = board[nx][ny] - 1;
        }
    }
    
    if (count != tcount) {
        cout << -1;
    } else {
        cout << max;
    }
    
    return 0;
}
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
    
    int n, m;
    cin >> n >> m;
    
    string tmp;
    int fire[n][m] = {0,};
    queue<pair<int, int>> q;
    
    int board[n][m] = {0,};
    pair<int, int> jihun_startPos;
    
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < tmp.length(); j++) {
            if (tmp[j] == '#') {
                fire[i][j] = -1;
                board[i][j] = -1;
            } else if (tmp[j] == 'J') {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    cout << 1;
                    return 0;
                }
                jihun_startPos = {i, j};
                board[i][j] = 1;
            } else if (tmp[j] == 'F') {
                q.push({i, j});
                fire[i][j] = 1;
            }
        }
    }
    
    pair<int, int> cursor;
    
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
            if (fire[nx][ny] != 0) continue;
            fire[nx][ny] = fire[cursor.X][cursor.Y] + 1;
            q.push({nx, ny});
        }
    }
    
    q.push(jihun_startPos);
    
    while (!q.empty()) {
        cursor = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            nx = cursor.X + dx[dir];
            ny = cursor.Y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] != 0) continue;
            if (fire[nx][ny] != 0 && board[cursor.X][cursor.Y] + 1 >= fire[nx][ny]) continue;
            board[nx][ny] = board[cursor.X][cursor.Y] + 1;
            
            if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1) {
                cout << board[nx][ny];
                return 0;
            }
            
            q.push({nx, ny});
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}
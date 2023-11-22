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
    
    int n, m, ans = 0;
    cin >> n >> m;
    
    int board[n][m];
    
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            board[i][j] = (int)(tmp[j] - '0');
        }
    }
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    pair<int, int> cursor;
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int nx, ny;
    
    while (!q.empty()) {
        cursor = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            nx = cursor.X + dx[i];
            ny = cursor.Y + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] != 1) continue;
            board[nx][ny] = board[cursor.X][cursor.Y] + 1;
            q.push({nx, ny});
        }
    }
    
    cout << board[n - 1][m - 1];
    return 0;
}
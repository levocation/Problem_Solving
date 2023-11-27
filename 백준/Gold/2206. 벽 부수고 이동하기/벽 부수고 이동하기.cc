#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <tuple>

#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    
    int nx, ny;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    string tmp;
    queue<tuple<int, int, int>> q;
    
    cin >> n >> m;
    int board[n][m];
    int dist[n][m][2];
    
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            board[i][j] = (tmp[j] == '1' ? 1 : 0);
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }
    
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;
    
    int x, y, broken;
    
    while (!q.empty()) {
        tie(x, y, broken) = q.front(); q.pop();
        
        if (x == n - 1 && y == m - 1) {
            cout << dist[x][y][broken];
            return 0;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            nx = x + dx[dir];
            ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if (board[nx][ny] == 0 && dist[nx][ny][broken] == -1) {
                // board[nx][ny] == 0 -> 탐색한 공간이 이동할 수 있는 공간인가?
                // dist[x][y][broken] == -1 -> 기존에 이동한 적이 없는 공간인가?
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({nx, ny, broken});
            }
            if (broken == 0 && board[nx][ny] == 1 && dist[nx][ny][1] == -1) {
                // broken == 0 -> 벽을 부순 적이 없는 상태인가?
                // board[nx][ny] == 0 -> 탐색한 공간이 이동할 수 없는 공간인가?
                // dist[x][y][1] == -1 -> 벽을 부순 상태로 해당 위치로 이동한 적이 없는가?
                dist[nx][ny][1] = dist[x][y][broken] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    
    cout << -1;
    return 0;
}
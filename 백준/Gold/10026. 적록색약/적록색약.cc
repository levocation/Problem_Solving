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
    
    
    int n, ans = 0;
    cin >> n;
    
    string tmp;
    int target = 0;
    int board[n][n] = {0,};
    int vst[n][n] = {0,};
    
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            switch (tmp[j]) {
                case 'R':
                    board[i][j] = 1;
                    break;
                case 'G':
                    board[i][j] = 2;
                    break;
                case 'B':
                    board[i][j] = 3;
                    break;
            }
        }
    }
    
    queue<pair<int, int>> q;
    pair<int, int> cur;
    int nx, ny;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    for (int asdf = 0; asdf < 2; asdf++) {
        ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vst[i][j]) {
                    target = board[i][j];
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        cur = q.front(); q.pop();
                        if (board[cur.X][cur.Y] == 1) board[cur.X][cur.Y] = 2;
                        for (int dir = 0; dir < 4; dir++) {
                            nx = cur.X + dx[dir];
                            ny = cur.Y + dy[dir];
                            
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                            if (board[nx][ny] != target || vst[nx][ny] == 1) continue;
                            vst[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                    ans++;
                }
            }
        }
        cout << ans << ' ';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vst[i][j] = 0;
            }
        }
    }
    
    return 0;
}
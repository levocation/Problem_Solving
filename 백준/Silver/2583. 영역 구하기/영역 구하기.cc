#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k, nx, ny, x1, y1, x2, y2;
    cin >> n >> m >> k;
    int board[n][m];
    for (int i = 0; i < n; i++) fill(board[i], board[i] + m, 0);
    queue<pair<int, int>> q;
    pair<int, int> cur;
    vector<int> v;
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    for (int cnt = 0; cnt < k; cnt++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                board[j][i] = 1;
            }
        }
    }
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 1;
                q.push({i, j});
                count = 1;
                
                while (!q.empty()) {
                    cur = q.front(); q.pop();
                    
                    for (int dir = 0; dir < 4; dir++) {
                        nx = cur.X + dx[dir];
                        ny = cur.Y + dy[dir];
                        
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (board[nx][ny] != 0) continue;
                        board[nx][ny] = 1;
                        q.push({nx, ny});
                        count++;
                    }
                }
                v.push_back(count);
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    cout << (int)(v.size()) << '\n';
    for (int num : v) {
        cout << num << ' ';
    }
    
    return 0;
}
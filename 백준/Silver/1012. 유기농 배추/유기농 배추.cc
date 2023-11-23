#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<pair<int, int>> q;
    pair<int, int> cur;
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int cnt, n, m, k, x, y, nx, ny, ans;
    cin >> cnt;
    while (cnt--) {
        cin >> m >> n >> k;
        int arr[n][m] = {0,};
        ans = 0;
        while (k--) {
            cin >> y >> x;
            arr[x][y] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) {
                    q.push({i, j});
                    arr[i][j] = 0;
                    
                    while (!q.empty()) {
                        cur = q.front(); q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            nx = cur.X + dx[dir];
                            ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (arr[nx][ny] != 1) continue;
                            arr[nx][ny] = 0;
                            q.push({nx, ny});
                        }
                    }
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
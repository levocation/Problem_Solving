#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));
    vector<vector<int>> vst(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    pair<int, int> cur;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (board[i][j] == 0) vst[i][j] = 0;
            else if (board[i][j] == 2) {
                q.push({i, j});
                vst[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        cur = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vst[nx][ny] != -1) continue;

            vst[nx][ny] = vst[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << vst[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
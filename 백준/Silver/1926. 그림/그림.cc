#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int width, height;
    cin >> height >> width;

    vector<vector<int>> board(height, vector<int>(width, 0));
    vector<vector<int>> vis(height, vector<int>(width, 0));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> q;

    int max_size = 0, tmp = 0;
    int cnt = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] && vis[i][j] == 0) {
                q.push({i, j});
                vis[i][j] = 1;
                cnt++;

                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    tmp++;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= height || ny < 0 || ny >= width) continue;
                        if (vis[nx][ny] || board[nx][ny] != 1) continue;

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }

                max_size = max(max_size, tmp);
                tmp = 0;
            }
        }
    }

    cout << cnt << '\n' << max_size;
    
    return 0;
}
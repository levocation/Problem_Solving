#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int** board = new int*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int** vis = new int*[n];
    for (int i = 0; i < n; i++) {
        vis[i] = new int[m];
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }
    int count = 0, max = 0, maxcount = 0;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    queue<pair<int, int>> q;
    pair<int, int> cursor;
    int nx, ny;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] && vis[i][j] != 1) {
                q = queue<pair<int, int>>();
                vis[i][j] = 1;
                maxcount = 0;
                q.push({ i, j });
                while (!q.empty()) {
                    cursor = q.front();
                    q.pop();
                    maxcount++; // 2번 해답
                    for (int k = 0; k < 4; k++) {
                        nx = cursor.first + dx[k];
                        ny = cursor.second + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        q.push({ nx, ny });
                    }
                }

                if (maxcount > max) max = maxcount;
                count++; // 1번 해답
            }
        }
    }

    cout << count << '\n' << max;

    return 0;
}
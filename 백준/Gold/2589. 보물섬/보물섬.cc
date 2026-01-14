#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0, width, height;
    char tmp;
    cin >> height >> width;

    vector<vector<int>> v(height, vector<int>(width));
    vector<pair<int, int>> pos_list;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> tmp;
            if (tmp == 'L') {
                v[i][j] = 0;
                pos_list.push_back({i, j});
            }
            else v[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    for (pair<int, int> pa : pos_list) {

        vector<vector<int>> board = v;
        
        q.push({pa.X, pa.Y});
        board[pa.X][pa.Y] = 1;

        while (!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = p.X + dx[dir];
                int ny = p.Y + dy[dir];
                if (nx < 0 || nx >= height || ny < 0 || ny >= width) continue;
                if (board[nx][ny] != 0) continue;

                board[nx][ny] = board[p.X][p.Y] + 1;
                q.push({nx, ny});

                if (board[nx][ny] > answer) answer = board[nx][ny];
            }
        }
    }

    cout << answer - 1;
    
    return 0;
}
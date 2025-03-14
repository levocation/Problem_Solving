#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int mn = 999, n, m, cctv_cnt, blind_spot = 0, mx, my, w;
vector<vector<int>> board;
vector<int> cctv;
vector<pair<int, int>> cctv_pos;

void bting(int depth) {
    if (depth > cctv_cnt) {
        if (blind_spot < mn) mn = blind_spot;
        return;
    }

    int c = cctv[depth - 1];
    pair<int, int> pos = cctv_pos[depth - 1];

    if (c == 1) { // 단방향
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        for (int dir = 0; dir < 4; dir++) {
            w = 1;
            while (true) {
                mx = pos.X + dx[dir] * w;
                my = pos.Y + dy[dir] * w;
                if (mx < 0 || mx >= n || my < 0 || my >= m || board[mx][my] == 6) {
                    break;
                }
    
                if (board[mx][my] == 0) {
                    blind_spot--;
                    board[mx][my] = -depth;
                }
                w++;
            }

            bting(depth + 1);
            
            w = 1;
            while (true) {
                mx = pos.X + dx[dir] * w;
                my = pos.Y + dy[dir] * w;
                if (mx < 0 || mx >= n || my < 0 || my >= m || board[mx][my] == 6) {
                    break;
                }
    
                if (board[mx][my] == -depth) {
                    blind_spot++;
                    board[mx][my] = 0;
                }
                w++;
            }
        }
    }
    else if (c == 2) { // 양쪽
        int dx[2][2] = {{1, -1}, {0, 0}};
        int dy[2][2] = {{0, 0}, {1, -1}};
        
        for (int d = 0; d < 2; d++) {
            for (int dir = 0; dir < 2; dir++) {
                w = 1;
                while (true) {
                    mx = pos.X + dx[d][dir] * w;
                    my = pos.Y + dy[d][dir] * w;
                    if (mx < 0 || mx >= n || my < 0 || my >= m || board[mx][my] == 6) {
                        break;
                    }
        
                    if (board[mx][my] == 0) {
                        blind_spot--;
                        board[mx][my] = -depth;
                    }
                    w++;
                }
            }
            
            bting(depth + 1);

            for (int dir = 0; dir < 2; dir++) {
                w = 1;
                while (true) {
                    mx = pos.X + dx[d][dir] * w;
                    my = pos.Y + dy[d][dir] * w;
                    if (mx < 0 || mx >= n || my < 0 || my >= m || board[mx][my] == 6) {
                        break;
                    }
        
                    if (board[mx][my] == -depth) {
                        blind_spot++;
                        board[mx][my] = 0;
                    }
                    w++;
                }
            }
        }
    }
    else if (c == 3) { // ㄱ자
        int dx[4][3] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int dy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (int d = 0; d < 4; d++) {
            for (int dir = 0; dir < 2; dir++) {
                w = 1;
                while (true) {
                    mx = pos.X + dx[d][dir] * w;
                    my = pos.Y + dy[d][dir] * w;
                    if (mx < 0 || mx >= n || my < 0 || my >= m || board[mx][my] == 6) {
                        break;
                    }
        
                    if (board[mx][my] == 0) {
                        blind_spot--;
                        board[mx][my] = -depth;
                    }
                    w++;
                }
            }
            
            bting(depth + 1);

            for (int dir = 0; dir < 2; dir++) {
                w = 1;
                while (true) {
                    mx = pos.X + dx[d][dir] * w;
                    my = pos.Y + dy[d][dir] * w;
                    if (mx < 0 || mx >= n || my < 0 || my >= m || board[mx][my] == 6) {
                        break;
                    }
        
                    if (board[mx][my] == -depth) {
                        blind_spot++;
                        board[mx][my] = 0;
                    }
                    w++;
                }
            }
        }
    }
    else if (c == 4) { // 3방향
        int dx[4][3] = {{-1, 0, 1}, {0, 1, 0}, {1, 0, -1}, {0, -1, 0}};
        int dy[4][3] = {{0, 1, 0}, {1, 0, -1}, {0, -1, 0}, {-1, 0, 1}};
        
        for (int d = 0; d < 4; d++) {
            for (int dir = 0; dir < 3; dir++) {
                w = 1;
                while (true) {
                    mx = pos.X + dx[d][dir] * w;
                    my = pos.Y + dy[d][dir] * w;
                    if (mx < 0 || mx >= n || my < 0 || my >= m || board[mx][my] == 6) {
                        break;
                    }
        
                    if (board[mx][my] == 0) {
                        blind_spot--;
                        board[mx][my] = -depth;
                    }
                    w++;
                }
            }
            
            bting(depth + 1);

            for (int dir = 0; dir < 3; dir++) {
                w = 1;
                while (true) {
                    mx = pos.X + dx[d][dir] * w;
                    my = pos.Y + dy[d][dir] * w;
                    if (mx < 0 || mx >= n || my < 0 || my >= m || board[mx][my] == 6) {
                        break;
                    }
        
                    if (board[mx][my] == -depth) {
                        blind_spot++;
                        board[mx][my] = 0;
                    }
                    w++;
                }
            }
        }
    }
    else if (c == 5) { // 전체
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        w = 1; // 이동에 대한 가중치
        for (int dir = 0; dir < 4; dir++) {
            mx = pos.X + dx[dir] * w;
            my = pos.Y + dy[dir] * w;
            if (mx < 0 || mx >= n || my < 0 || my >= m || board[mx][my] == 6) {
                w = 1;
                continue;
            }

            if (board[mx][my] == 0) {
                blind_spot--;
                board[mx][my] = -depth;
            }
            dir--;
            w++;
        }

        bting(depth + 1);

        w = 1; // 이동에 대한 가중치
        for (int dir = 0; dir < 4; dir++) {
            mx = pos.X + dx[dir] * w;
            my = pos.Y + dy[dir] * w;
            if (mx < 0 || mx >= n || my < 0 || my >= m || board[mx][my] == 6) {
                w = 1;
                continue;
            }

            if (board[mx][my] == -depth) {
                blind_spot++;
                board[mx][my] = 0;
            }
            dir--;
            w++;
        }
    }
}

int main() {

    cin >> n >> m;
    blind_spot = n * m;
    
    board = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 6) {
                blind_spot--;
            } else if (board[i][j] >= 1 && board[i][j] <= 5) {
                cctv.push_back(board[i][j]);
                cctv_pos.push_back({i, j});
                cctv_cnt++;
                blind_spot--;
            }
        }
    }

    bting(1);

    // debug
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    */
    
    cout << mn;
    
    return 0;
}
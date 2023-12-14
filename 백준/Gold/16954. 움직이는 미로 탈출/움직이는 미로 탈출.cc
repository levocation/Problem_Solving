#include <iostream>
#include <string>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int board[8][8] = {0,};
    string tmp;
    
    for (int i = 0; i < 8; i++) {
        cin >> tmp;
        for (int j = 0; j < 8; j++) {
            if (tmp[j] == '#') board[i][j] = -1;
        }
    }
    
    //board[7][0] = 1;
    
    pair<int, int> cur;
    queue<pair<int, int>> q;
    
    q.push({7, 0});
    
    int dx[9] = {0, 0, 1, -1, 1, 1, -1, -1, 0};
    int dy[9] = {1, -1, 0, 0, 1, -1, 1, -1, 0};
    int nx[2];
    int ny;
    bool isArrived = false;
    // 상하좌우, 대각선 4방향, 제자리(부동)
    
    while (!q.empty()) {
        if (isArrived) break;
        cur = q.front(); q.pop();
        
        for (int dir = 0; dir < 9; dir++) {
            nx[0] = cur.X + dx[dir];
            nx[1] = cur.X + dx[dir] - 1;
            ny = cur.Y + dy[dir];
            
            if (nx[0] >= 8 || nx[1] >= 8 || ny < 0 || ny >= 8) continue;
            if (nx[0] < 0) {
                // nx < 0 일 경우, board에서 nx로 접근 시 에러 발생
                isArrived = true;
                break;
            } else if (nx[1] < 0) {
                // nx < 0 일 경우, board에서 nx로 접근 시 에러 발생
                if (board[nx[0]][ny] != 0) continue;
                isArrived = true;
                break;
            }
            if (dx[dir] == 0 && dy[dir] == 0) {
                if (board[nx[1]][ny] != 0) continue;
            } else {
                if (board[nx[0]][ny] != 0 
               || board[nx[1]][ny] != 0) continue;
            }
            if (dx[dir] != 0 || dy[dir] != 0) board[nx[1]][ny] = 1;
            q.push({nx[1], ny});
        }
    }
    
    cout << isArrived;
    
    return 0;
}
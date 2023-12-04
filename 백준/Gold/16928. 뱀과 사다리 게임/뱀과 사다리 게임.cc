#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int board[101] = {0,};
    int vst[101] = {0,};
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= 100; i++) {
        board[i] = i;
    }
    for (int i = 0; i < n + m; i++) {
        cin >> a >> b;
        board[a] = b;
    }
    
    queue<pair<int, int>> q;
    // pair<현재위치, 주사위굴린횟수>
    pair<int, int> cur;
    q.push({1, 0});
    vst[1] = 0;
    int nx;
    
    while (!q.empty()) {
        cur = q.front(); q.pop();
        if (cur.X == 0) continue;
        if (cur.X == 100) {
            cout << cur.Y;
            break;
        }
        for (int i = 1; i <= 6; i++) {
            nx = cur.X + i;
            if (nx > 100) continue;
            if (vst[nx]) continue;
            q.push(make_pair(board[cur.X + i], cur.Y + 1));
            vst[nx] = vst[cur.X] + 1;
            if (board[cur.X + i] != cur.X + i) board[cur.X + i] = 0;
        }
    }
    
    return 0;
}
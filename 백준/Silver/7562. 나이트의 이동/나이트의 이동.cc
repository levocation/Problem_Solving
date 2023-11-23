#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, l;
    cin >> n;
    
    pair<int, int> s, e, cur;
    queue<pair<int, int>> q;
    
    int nx, ny;
    int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
    int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
    
    while (n--) {
        cin >> l;
        int arr[l][l] = {0,};
        for (int i = 0; i < l; i++) fill(arr[i], arr[i] + l, 0);
        cin >> s.X >> s.Y >> e.X >> e.Y;
        
        arr[s.X][s.Y] = 1;
        q = queue<pair<int, int>>();
        q.push({s.X, s.Y});
        
        while (!q.empty()) {
            cur = q.front(); q.pop();
            if (cur.X == e.X && cur.Y == e.Y) {
                cout << arr[cur.X][cur.Y] - 1 << '\n';
                break;
            }
            for (int dir = 0; dir < 8; dir++) {
                nx = cur.X + dx[dir];
                ny = cur.Y + dy[dir];
                
                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if (arr[nx][ny] > 0) continue;
                arr[nx][ny] = arr[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return 0;
}
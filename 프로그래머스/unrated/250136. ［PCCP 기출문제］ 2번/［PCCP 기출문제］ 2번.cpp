#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <set>

#define X first
#define Y second

using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;
    int cnt = 0, num = 1, sum = 0;
    
    queue<pair<int, int>> q;
    set<int> s;
    
    int arr[60000] = {0,};
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int nx, ny;
    pair<int, int> cur;
    
    int n = land.size(), m = land[0].size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (land[i][j] == 1) {
                q.push({i, j});
                num++;
                cnt = 1;
                land[i][j] = num;
                
                while (!q.empty()) {
                    cur = q.front(); q.pop();
                    
                    for (int dir = 0; dir < 4; dir++) {
                        nx = cur.X + dx[dir];
                        ny = cur.Y + dy[dir];
                        
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (land[nx][ny] != 1) continue;
                        land[nx][ny] = num;
                        cnt++;
                        q.push({nx, ny});
                    }
                }
                arr[num] = cnt;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        s.clear();
        sum = 0;
        for (int j = 0; j < n; j++) {
            if (land[j][i]) {
                s.insert(land[j][i]);
            }
        }
        for (int cost : s) {
            sum += arr[cost];
        }
        if (sum > answer) answer = sum;
    }
    
    return answer;
}
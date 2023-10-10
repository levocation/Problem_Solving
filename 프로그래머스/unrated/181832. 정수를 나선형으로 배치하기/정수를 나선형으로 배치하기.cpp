#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    int dx = 1;
    int dy = 0;
    
    int x = 0;
    int y = 0;
    
    int direction = 3;
    // 1 : 위쪽
    // 2 : 왼쪽
    // 3 : 오른쪽
    // 4 : 아래쪽
    
    // 기본 방향은 3
    
    for (int i = 1; i <= n * n; i++) {
        answer[y][x] = i;
        
        if (direction == 3 && 
           (x + 1 >= n || answer[y][x + 1] != 0)) {
            direction = 4;
            
            dx = 0;
            dy = 1;
        } else if (direction == 4 && 
           (y + 1 >= n || answer[y + 1][x] != 0)) {
            direction = 2;
            
            dx = -1;
            dy = 0;
        } else if (direction == 2 && 
           (x - 1 < 0 || answer[y][x - 1] != 0)) {
            direction = 1;
            
            dx = 0;
            dy = -1;
        } else if (direction == 1 && 
           (y - 1 < 0 || answer[y - 1][x] != 0)) {
            direction = 3;
            
            dx = 1;
            dy = 0;
        }
        
        y += dy;
        x += dx;
    }
    
    return answer;
}
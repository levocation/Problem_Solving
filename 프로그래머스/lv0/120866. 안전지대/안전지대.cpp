#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int len = board.size();
    vector<vector<int>> b(len, vector<int>(len, 0));
    // 위험구역을 담을 배열을 따로 생성
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (board[i][j] == 1) {
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        if (k <= -1 || k >= len 
                           || l <= -1 || l >= len) {
                            continue;
                        }
                        b[k][l] = 1;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (b[i][j] == 0) {
                answer++;
            }
        }
    }
    
    return answer;
}
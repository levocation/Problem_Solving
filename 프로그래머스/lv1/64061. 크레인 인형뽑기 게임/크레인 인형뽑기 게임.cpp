#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> doll_list;
    
    for (int num : moves) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][num-1] != 0) {
                doll_list.emplace_back(board[i][num-1]);
                board[i][num-1] = 0;
                
                if (doll_list.size() >= 2 
                   && doll_list[doll_list.size() - 1] 
                       == doll_list[doll_list.size() - 2]) {
                    doll_list.pop_back();
                    doll_list.pop_back();
                    answer += 2;
                }
                break;
            }
        }
    }
    
    return answer;
}
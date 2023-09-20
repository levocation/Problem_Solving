#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    
    int width = board[0];
    int height = board[1];
    
    int x = width / 2;
    int y = height / 2;
    
    for (string str : keyinput) {
        if (str == "left") {
            if (x - 1 >= 0) {
                x--;
            }
        } else if (str == "right") {
            if (x + 1 <= width - 1) {
                x++;
            }
        } else if (str == "up") {
            if (y + 1 <= height - 1) {
                y++;
            }
        } else if (str == "down") {
            if (y - 1 >= 0) {
                y--;
            }
        }
    }
    
    answer.emplace_back(x - (width / 2));
    answer.emplace_back(y - (height / 2));
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    vector<int> temp;
    
    for (vector<int> command : commands) {
        temp.clear();
        for (int i = command[0] - 1; i < command[1]; i++) {
            temp.emplace_back(array[i]);
        }
        sort(temp.begin(), temp.end());
        answer.emplace_back(temp[command[2] - 1]);
    }
    
    return answer;
}
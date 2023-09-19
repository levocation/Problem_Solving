#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer = num_list;
    
    int idx = answer.size();
    
    if (answer[idx - 1] > answer[idx - 2]) {
        answer.emplace_back(answer[idx - 1] - answer[idx - 2]);
    } else {
        answer.emplace_back(answer[idx - 1] * 2);
    }
    
    return answer;
}
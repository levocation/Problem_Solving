#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    for (int i = num_list.size() - 1; i >= 0; i--) {
        answer.emplace_back(num_list[i]);
    }
    
    return answer;
}
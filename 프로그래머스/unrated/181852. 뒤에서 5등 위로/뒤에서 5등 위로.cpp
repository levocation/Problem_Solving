#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    vector<int> t = num_list;
    
    sort(t.begin(), t.end());
    
    for (int i = 5; i < t.size(); i++) {
        answer.emplace_back(t[i]);
    }
    
    return answer;
}
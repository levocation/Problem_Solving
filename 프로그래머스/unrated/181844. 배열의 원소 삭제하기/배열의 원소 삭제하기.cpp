#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    
    unordered_map<int, bool> m;
    
    for (int i : delete_list) {
        m.insert({i, true});
    }
    
    for (int i = 0; i < arr.size(); i++) {
        if (m.find(arr[i]) == m.end()) {
            answer.emplace_back(arr[i]);
        }
    }
    
    return answer;
}
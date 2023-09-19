#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer = arr;
    
    if (arr.size() > arr[0].size()) {
        for (int i = 0; i < arr.size() - arr[0].size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                answer[j].emplace_back(0);
            }
        }
    } else {
        vector<int> v(arr[0].size(), 0);
        for (int i = 0; i < arr[0].size() - arr.size(); i++) {
            answer.emplace_back(v);
        }
    }
    
    return answer;
}
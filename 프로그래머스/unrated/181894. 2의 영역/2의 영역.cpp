#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int start_idx = -1;
    int end_idx = -1;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 2) {
            start_idx = i;
            break;
        }
    }
    
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] == 2) {
            end_idx = i;
            break;
        }
    }
    
    if (start_idx == -1) {
        answer.emplace_back(-1);
    } else if (start_idx == end_idx) {
        answer.emplace_back(2);
    } else {
        for (int i = start_idx; i <= end_idx; i++) {
            answer.emplace_back(arr[i]);
        }
    }
    
    return answer;
}
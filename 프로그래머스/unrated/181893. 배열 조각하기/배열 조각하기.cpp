#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    
    int start_idx = 0;
    int end_idx = query.size() - 1;
    
    for (int i = 0; i < query.size(); i++) {
        if (i % 2 == 0) { // 짝수 인덱스
            end_idx = start_idx + query[i];
        } else {
            start_idx = start_idx + query[i];
        }
    }
    
    for (int i = start_idx; i <= end_idx; i++) {
        answer.emplace_back(arr[i]);
    }
    
    return answer;
}
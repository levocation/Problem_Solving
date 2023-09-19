#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer = arr;
    
    int temp = -1;
    int idx1 = -1;
    int idx2 = -1;
    
    for (int i = 0; i < queries.size(); i++) {
        idx1 = queries[i][0];
        idx2 = queries[i][1];
        
        temp = answer[idx1];
        answer[idx1] = answer[idx2];
        answer[idx2] = temp;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    map<int, bool> m;
    
    for (int i = 0; i < arr.size(); i++) {
        if (m.find(arr[i]) == m.end()) {
            m.insert({arr[i], true});
            answer.emplace_back(arr[i]);
            if (answer.size() >= k) {
                break;
            }
        }
    }
    
    for (int i = 0; i < k - m.size(); i++) {
        answer.emplace_back(-1);
    }
    
    return answer;
}
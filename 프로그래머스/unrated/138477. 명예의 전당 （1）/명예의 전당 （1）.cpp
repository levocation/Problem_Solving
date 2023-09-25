#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    vector<int> t;
    
    for (int num : score) {
        if (t.size() >= k) {
            if (t[t.size() - 1] < num) {
                t.pop_back();
                t.emplace_back(num);
            }
        } else {
            t.emplace_back(num);
        }
        
        sort(t.begin(), t.end(), greater<>());
        
        answer.emplace_back(t[t.size() - 1]);
    }
    
    return answer;
}
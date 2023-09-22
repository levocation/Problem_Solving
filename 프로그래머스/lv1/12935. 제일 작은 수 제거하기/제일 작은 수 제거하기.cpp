#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> t = arr;
    
    sort(arr.begin(), arr.end());
    int min = arr[0];
    
    for (int i = 0; i < t.size(); i++) {
        if (t[i] != min) {
            answer.emplace_back(t[i]);
        }
    }
    
    if (answer.size() == 0) {
        answer.emplace_back(-1);
    }
    
    return answer;
}
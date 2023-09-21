#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    map<int, int> cnt;
    // map<number, count>
    
    for (int i : array) {
        if (cnt.find(i) == cnt.end()) {
            cnt.insert({i, 1});
        } else {
            cnt.find(i)->second += 1;
        }
    }
    
    vector<int> t;
    
    int max_count = -1;
    int max_number = 0;
    
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        if (it->second > max_count) {
            max_count = it->second;
            max_number = it->first;
        }
        t.emplace_back(it->second);
    }
    
    sort(t.begin(), t.end());
    
    if (t.size() != 1 && t[t.size() - 1] == t[t.size() - 2]) {
        answer = -1;
    } else {
        answer = max_number;
    }
    
    return answer;
}
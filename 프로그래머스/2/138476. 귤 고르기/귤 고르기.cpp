#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    int tangerine_count = 0;
    
    map<int, int> m;
    
    for (int num : tangerine) {
        if (m.find(num) == m.end()) {
            m.insert({num, 1});
        } else {
            m.find(num)->second++;
        }
    }
    
    vector<pair<int, int>> v(m.begin(), m.end());
    
    sort(v.begin(), v.end(), comp);
    
    for (int i = 0; i < v.size(); i++) {
        tangerine_count += v[i].second;
        
        if (tangerine_count >= k) {
            answer = i + 1;
            break;
        }
        
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;
    
    for (vector<string> v : clothes) {
        if (m.find(v[1]) == m.end()) {
            m.insert({v[1], 2});
        } else {
            m.find(v[1])->second++;
        }
    }
    
    for (auto it = m.begin(); it != m.end(); it++) {
        answer *= (*it).second;
    }
    
    return --answer;
}
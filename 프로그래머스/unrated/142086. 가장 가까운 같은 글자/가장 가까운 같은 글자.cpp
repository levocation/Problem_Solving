#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    map<char, int> m;
    // map<문자, 인덱스>
    
    for (int i = 0; i < s.length(); i++) {
        if (m.find(s[i]) == m.end()) {
            answer.emplace_back(-1);
            m.insert({s[i], i});
        } else {
            answer.emplace_back(i - m.find(s[i])->second);
            m.find(s[i])->second = i;
        }
    }
    
    return answer;
}
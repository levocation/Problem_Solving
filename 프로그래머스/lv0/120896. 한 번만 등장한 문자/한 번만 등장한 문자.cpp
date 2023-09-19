#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    
    map<char, int> m;
    
    for (char ch : s) {
        if (m.find(ch) == m.end()) {
            m.insert({ch, 1});
        } else {
            m.find(ch)->second += 1;
        }
    }
    
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == 1) {
            answer += (iter->first);
        }
    }
    
    return answer;
}
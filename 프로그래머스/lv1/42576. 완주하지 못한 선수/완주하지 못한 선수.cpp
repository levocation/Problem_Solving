#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> m;
    
    for (string member : participant) {
        if (m.find(member) != m.end()) {
            m.find(member)->second++;
        } else {
            m.insert({member, 1});
        }
    }
    
    for (string member : completion) {
        m.find(member)->second--;
        if (m.find(member)->second <= 0) {
            m.erase(member);
        }
    }
    
    answer = m.begin()->first;
    
    return answer;
}

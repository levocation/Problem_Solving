#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    string dict_queue;
    
    map<string, int> m;
    
    string tmp;
    
    for (int i = 1; i <= 26; i++) {
        tmp = (char)(64 + i);
        m.insert({tmp, i});
    }
    
    int m_len = 26;
    
    for (char ch : msg) {
        if (m.find(dict_queue + ch) == m.end()) {
            answer.emplace_back(m.find(dict_queue)->second);
            m.insert({dict_queue + ch, ++m_len});
            dict_queue = ch;
        } else {
            dict_queue += ch;
        }
    }
    
    if (dict_queue != "") {
        answer.emplace_back(m.find(dict_queue)->second);
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<pair<int, string>> log;
    // vector<pair<입장/퇴장 여부, id>>
    
    map<string, string> data;
    // map<id, nickname>
    
    stringstream ss;
    string buffer;
    string id;
    string nickname;
    
    for (string r : record) {
        ss = stringstream(r);
        
        getline(ss, buffer, ' ');
        if (buffer == "Enter") {
            getline(ss, buffer, ' ');
            id = buffer;
            
            log.emplace_back(make_pair(1, id));
            getline(ss, buffer, ' ');
            nickname = buffer;
            if (data.find(id) == data.end()) {
                data.insert({id, nickname});
            } else {
                data.find(id)->second = nickname;
            }
            
        } else if (buffer == "Leave") {
            getline(ss, buffer, ' ');
            id = buffer;
            
            log.emplace_back(make_pair(2, id));
        } else if (buffer == "Change") {
            getline(ss, buffer, ' ');
            id = buffer;
            getline(ss, buffer, ' ');
            nickname = buffer;
            
            data.find(id)->second = nickname;
        }
    }
    
    for (int i = 0; i < log.size(); i++) {
        if (log[i].first == 1) {
            answer.emplace_back(data.find(log[i].second)->second + "님이 들어왔습니다.");
        } else {
            answer.emplace_back(data.find(log[i].second)->second + "님이 나갔습니다.");
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    map<string, int> idx_map;
    map<string, vector<string>> report_map;
    // 신고당한 사람, 신고한 사람들 배열
    
    string buffer;
    
    string reported_user;
    string report_user;
    
    bool in_user = false;
    
    for (int i = 0; i < id_list.size(); i++) {
        report_map.insert({id_list[i], vector<string>()});
        idx_map.insert({id_list[i], i});
    }
    
    for (int i = 0; i < report.size(); i++) {
        in_user = false;
        stringstream ss(report[i]);
        
        getline(ss, buffer, ' ');
        report_user = buffer;
        getline(ss, buffer, ' ');
        reported_user = buffer;
        
        for (string str : report_map.find(reported_user)->second) {
            if (str == report_user) {
                in_user = true;
                break;
            }
        }
        
        if (!in_user) {
            report_map.find(reported_user)->second.emplace_back(
                report_user);
        }
    }
    
    vector<string> temp;
    
    for (int i = 0; i < id_list.size(); i++) {
        temp = report_map.find(id_list[i])->second;
        if (temp.size() >= k) {
            for (string str : temp) {
                answer[idx_map.find(str)->second]++;
            }
            
        }
    }
    
    return answer;
}
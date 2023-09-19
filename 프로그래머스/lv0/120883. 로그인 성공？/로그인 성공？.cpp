#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    
    map<string, string> mem_info;
    
    for (int i = 0; i < db.size(); i++) {
        mem_info.insert({db[i][0], db[i][1]});
    }
    
    if (mem_info.find(id_pw[0]) == mem_info.end()) {
        answer = "fail";
    } else if (mem_info.find(id_pw[0])->second == id_pw[1]) {
        answer = "login";
    } else {
        answer = "wrong pw";
    }
    
    return answer;
}
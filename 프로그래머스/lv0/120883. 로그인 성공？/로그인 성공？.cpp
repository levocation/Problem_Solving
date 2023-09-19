#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    
    // 풀이 요약
    // id와 pw는 한 쌍이므로
    // 빠른 탐색을 통해 map을 사용
    
    string answer = "";
    
    map<string, string> mem_info;
    // id와 pw가 한 쌍이므로
    // 빠른 탐색을 위해 map을 사용하여
    // <key, value>를 <id, pw>로 설정한다.
    
    for (int i = 0; i < db.size(); i++) {
        mem_info.insert({db[i][0], db[i][1]});
    }
    // db의 데이터를 <id, pw> 형태로 map에 insert
    
    if (mem_info.find(id_pw[0]) == mem_info.end()) {
        // mem_info에서 id가  존재하지 않으면
        // map     에서 key가 존재하지 않으면
        answer = "fail";
    } else if (mem_info.find(id_pw[0])->second == id_pw[1]) {
        // mem_info에서 검색한 id랑  같은 쌍인 pw의    값이 입력받은 pw의    값과 같다면
        // map     에서 검색한 key랑 같은 쌍인 value의 값이 입력받은 value의 값과 같다면
        answer = "login";
    } else {
        // mem_info에서 검색한 id랑  같은 쌍인 pw의    값이 입력받은 pw의    값과 다르면
        // map     에서 검색한 key랑 같은 쌍인 value의 값이 입력받은 value의 값과 다르면
        answer = "wrong pw";
    }
    
    return answer;
}
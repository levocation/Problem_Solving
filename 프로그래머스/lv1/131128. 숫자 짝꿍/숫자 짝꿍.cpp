#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    map<int, int> x_m;
    // <num, count> X의 map
    
    map<int, int> y_m;
    // <num, count> Y의 map
    
    for (char ch : X) {
        if (x_m.find(ch - '0') == x_m.end()) {
            x_m.insert({ch - '0', 1});
        } else {
            x_m.find(ch - '0')->second++;
        }
    }
    
    for (char ch : Y) {
        if (y_m.find(ch - '0') == y_m.end()) {
            y_m.insert({ch - '0', 1});
        } else {
            y_m.find(ch - '0')->second++;
        }
    }
    
    for (int i = 9; i >= 0; i--) {
        if (x_m.find(i) == x_m.end() || y_m.find(i) == y_m.end()) {
            continue;
        } else {
            for (int j = 0; j < 
                 (x_m.find(i)->second < y_m.find(i)->second 
                 ? x_m.find(i)->second : y_m.find(i)->second); j++) {
                answer += to_string(i);
            }
        }
    }
    
    if (answer.length() <= 0) {
        answer = "-1";
    } else if (answer[0] == '0') {
        // answer의 맨 앞자리가 0이라는 것은
        // answer에 0만 들어왔다는 뜻
        answer = "0";
    }
    
    return answer;
}
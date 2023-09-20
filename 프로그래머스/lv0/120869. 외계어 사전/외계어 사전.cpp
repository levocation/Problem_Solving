#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    
    int find_count = 0;
    
    for (int i = 0; i < dic.size(); i++) {
        find_count = 0;
        for (string str : spell) {
            if (dic[i].find(str) != string::npos) {
                find_count++;
            }
        }
        
        if (find_count >= spell.size()) {
            answer = 1;
            break;
        }
    }
    
    return answer;
}
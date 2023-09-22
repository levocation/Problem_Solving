#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for (int i = 0, cnt = 0; i < s.size(); i++, cnt++) {
        if (s[i] == ' ') {
            cnt = -1;
            answer += ' ';
        } else if (cnt % 2 == 0) {
            answer += toupper(s[i]);
        } else if (cnt % 2 == 1) {
            answer += tolower(s[i]);
        }
    }
    
    return answer;
}
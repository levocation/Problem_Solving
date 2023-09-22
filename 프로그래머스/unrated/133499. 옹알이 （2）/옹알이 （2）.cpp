#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string s = "";
    int count = 0;
    
    for (int i = 0; i < babbling.size(); i++) {
        s = babbling[i];
        count = 0;
        
        // 연속되는 문자열 있는지 확인
        if (s.find("ayaaya") != string::npos 
           || s.find("yeye") != string::npos 
           || s.find("woowoo") != string::npos 
           || s.find("mama") != string::npos ) {
            count = 6974;
        } else {
            while (s.find("aya") != string::npos)
                s.replace(s.find("aya"), 3, "   ");
            while (s.find("ye") != string::npos)
                s.replace(s.find("ye"), 2, "  ");
            while (s.find("woo") != string::npos)
                s.replace(s.find("woo"), 3, "   ");
            while (s.find("ma") != string::npos)
                s.replace(s.find("ma"), 2, "  ");
            
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != ' ') {
                    count++;
                    break;
                }
            }
            
            if (count <= 0) {
                answer++;
            }
        }
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";
    
    for (char ch : rsp) {
        if (ch == '0') {
            answer += "5";
        } else if (ch == '2') {
            answer += "0";
        } else {
            answer += "2";
        }
    }
    
    return answer;
}
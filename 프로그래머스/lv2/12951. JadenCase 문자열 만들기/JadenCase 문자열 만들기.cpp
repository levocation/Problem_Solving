#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool isUpper = true;
    
    for (char& ch : s) {
        if (ch == ' ') {
            // ch는 공백
            isUpper = true;
        } else if (ch - '0' >= 0 && ch - '0' <= 9) {
            // ch는 숫자
            isUpper = false;
        } else {
            ch = (isUpper ? toupper(ch) : tolower(ch));
            isUpper = false;
        }
    }
    
    return s;
}
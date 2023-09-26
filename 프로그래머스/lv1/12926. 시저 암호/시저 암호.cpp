#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (char ch : s) {
        if (ch == ' ') {
            answer += " ";
        } else {
            if (ch >= 65 && ch <= 90) {
                if (ch + n > 90) {
                    answer += (ch + n - 26);
                } else {
                    answer += (ch + n);
                }
            } else if (ch >= 97 && ch <= 122) {
                if (ch + n > 122) {
                    answer += (ch + n - 26);
                } else {
                    answer += (ch + n);
                }
            }
        }
    }
    
    return answer;
}

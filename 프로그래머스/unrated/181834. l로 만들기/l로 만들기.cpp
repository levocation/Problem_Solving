#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for (char ch : myString) {
        if (ch < 'l') {
            answer += "l";
        } else {
            answer += ch;
        }
    }
    
    return answer;
}
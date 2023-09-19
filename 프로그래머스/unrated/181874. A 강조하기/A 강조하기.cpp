#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for (char ch : myString) {
        if (ch == 'a') {
            answer += 'A';
        } else if (ch != 'A' && ch == toupper(ch)) {
            answer += tolower(ch);
        } else {
            answer += ch;
        }
    }
    
    return answer;
}
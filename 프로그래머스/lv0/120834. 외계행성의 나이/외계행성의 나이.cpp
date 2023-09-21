#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    
    string t = to_string(age);
    
    for (char ch : t) {
        answer += (ch - '0' + 'a');
    }
    
    return answer;
}
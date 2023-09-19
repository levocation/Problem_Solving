#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    
    int idx = myString.find_last_of(pat);
    
    for (int i = 0; i <= idx; i++) {
        answer += myString[i];
    }
    
    return answer;
}
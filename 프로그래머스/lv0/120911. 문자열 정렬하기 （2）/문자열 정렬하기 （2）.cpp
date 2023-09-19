#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = my_string;
    
    for (char& ch : answer) {
        ch = tolower(ch);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
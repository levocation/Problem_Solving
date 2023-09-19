#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    int i = 0;
    
    for (i = 0; n_str[i] == '0'; i++) {}
    
    answer = n_str.substr(i, n_str.size() - i);
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    string str = myString;
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'A') {
            str[i] = 'B';
        } else {
            str[i] = 'A';
        }
    }
    
    if (str.find(pat) != string::npos) answer = 1;
    
    return answer;
}
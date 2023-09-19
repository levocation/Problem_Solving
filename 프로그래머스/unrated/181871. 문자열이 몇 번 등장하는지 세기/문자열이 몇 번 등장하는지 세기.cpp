#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    string str = myString;
    string new_str = "";
    
    int idx = -1;
    
    for (int i = 0; i < myString.size() - pat.size() + 1; i++) {
        if (myString.substr(i, pat.size()) == pat) {
            answer++;
        }
    }
    
    return answer;
}
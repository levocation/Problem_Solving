#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int braket_count = 0;
    
    for (char ch : s) {
        if (ch == '(') {
            braket_count++;
        } else if (ch == ')') {
            braket_count--;
            if (braket_count <= -1) {
                answer = false;
                return answer;
            }
        }
    }
    
    if (braket_count > 0) {
        answer = false;
    } else if (s[s.length() - 1] == '(') {
        answer = false;
    } else {
        answer = true;
    }
    
    return answer;
}
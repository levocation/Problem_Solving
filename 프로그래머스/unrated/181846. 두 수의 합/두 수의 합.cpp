#include <string>
#include <vector>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    
    string a1 = a;
    string b1 = b;
    
    int carry = 0;
    int len = (a1.length() > b1.length()) ? b1.length() : a1.length();
    
    if (a1.length() > b1.length()) {
        for (int i = 0; i < a1.length() - len; i++) {
            b1 = "0" + b1;
        }
    } else {
        for (int i = 0; i < b1.length() - len; i++) {
            a1 = "0" + a1;
        }
    }
    
    int v1 = 0, v2 = 0;
    bool isCarry = false;
    
    for (int i = a1.length() - 1; i >= 0; i--) {
        v1 = (int)(a1[i] - 48);
        v2 = (int)(b1[i] - 48);
        isCarry = ((v1 + v2 + carry) >= 10);
        
        answer = to_string(isCarry 
                           ? v1 + v2 + carry - 10 
                           : v1 + v2 + carry) + answer;
        
        if (isCarry) {
            carry = 1;
        } else {
            carry = 0;
        }
        
    }
    
    if (carry == 1) {
        answer = "1" + answer;
    }
    
    return answer;
}
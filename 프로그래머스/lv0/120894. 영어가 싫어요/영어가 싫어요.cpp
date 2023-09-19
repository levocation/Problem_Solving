#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    
    string temp;
    
    for (int i = 0; i <= numbers.length() - 1; i += 0) {
        temp = numbers.substr(i, 5);
        
        if (temp.substr(0, 3) == "one") {
            answer = answer * 10 + 1;
            i += 3;
        } else if (temp.substr(0, 3) == "two") {
            answer = answer * 10 + 2;
            i += 3;
        } else if (temp.substr(0, 5) == "three") {
            answer = answer * 10 + 3;
            i += 5;
        } else if (temp.substr(0, 4) == "four") {
            answer = answer * 10 + 4;
            i += 4;
        } else if (temp.substr(0, 4) == "five") {
            answer = answer * 10 + 5;
            i += 4;
        } else if (temp.substr(0, 3) == "six") {
            answer = answer * 10 + 6;
            i += 3;
        } else if (temp.substr(0, 5) == "seven") {
            answer = answer * 10 + 7;
            i += 5;
        } else if (temp.substr(0, 5) == "eight") {
            answer = answer * 10 + 8;
            i += 5;
        } else if (temp.substr(0, 4) == "nine") {
            answer = answer * 10 + 9;
            i += 4;
        } else if (temp.substr(0, 4) == "zero") {
            answer = answer * 10 + 0;
            i += 4;
        }
    }
    
    return answer;
}
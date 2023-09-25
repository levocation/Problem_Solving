#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    while (s.find("zero") != string::npos) {
        s.replace(s.find("zero"), 4, "0");
    }
    
    while (s.find("one") != string::npos) {
        s.replace(s.find("one"), 3, "1");
    }
    
    while (s.find("two") != string::npos) {
        s.replace(s.find("two"), 3, "2");
    }
    
    while (s.find("three") != string::npos) {
        s.replace(s.find("three"), 5, "3");
    }
    
    while (s.find("four") != string::npos) {
        s.replace(s.find("four"), 4, "4");
    }
    
    while (s.find("five") != string::npos) {
        s.replace(s.find("five"), 4, "5");
    }
    
    while (s.find("six") != string::npos) {
        s.replace(s.find("six"), 3, "6");
    }
    
    while (s.find("seven") != string::npos) {
        s.replace(s.find("seven"), 5, "7");
    }
    
    while (s.find("eight") != string::npos) {
        s.replace(s.find("eight"), 5, "8");
    }
    
    while (s.find("nine") != string::npos) {
        s.replace(s.find("nine"), 4, "9");
    }
    
    answer = stoi(s);
    
    return answer;
}
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    string buffer;
    int int_buffer;
    
    stringstream ss(s);
    
    while (getline(ss, buffer, ' ')) {
        
        if (buffer == "Z") {
            answer -= int_buffer;
        } else {
            int_buffer = stoi(buffer);
            answer += int_buffer;
        }
    }
    
    return answer;
}
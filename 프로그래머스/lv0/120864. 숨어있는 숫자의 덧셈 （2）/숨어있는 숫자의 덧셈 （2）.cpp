#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    string str = my_string;
    
    for (char& ch : str) {
        if (ch - '0' > 9) {
            ch = '|';
        }
    }
    
    stringstream ss(str);
    string buffer;
    
    while (getline(ss, buffer, '|')) {
        if (buffer != "") {
            answer += stoi(buffer);
        }
    }
    
    return answer;
}
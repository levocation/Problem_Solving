#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    
    string t = myStr;
    
    for (int i = 0; i < myStr.size(); i++) {
        if (myStr[i] == 'a' || myStr[i] == 'b' || myStr[i] == 'c') {
            myStr[i] = '|';
        }
    }
    
    stringstream ss(myStr);
    string buffer;
    
    while (getline(ss, buffer, '|')) {
        if (buffer != "") {
            answer.emplace_back(buffer);
        }
    }
    
    if (answer.size() <= 0) {
        answer.emplace_back("EMPTY");
    }
    
    
    return answer;
}
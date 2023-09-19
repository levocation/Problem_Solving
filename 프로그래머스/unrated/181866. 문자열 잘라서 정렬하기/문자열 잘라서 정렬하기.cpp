#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    
    string buffer;
    stringstream ss(myString);
    
    while (getline(ss, buffer, 'x')) {
        if (buffer != "") {
            answer.emplace_back(buffer);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
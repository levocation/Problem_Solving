#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    
    string buffer;
    stringstream ss(myString);
    
    while (getline(ss, buffer, 'x')) {
        answer.emplace_back(buffer.size());
    }
    
    if (myString[myString.size() - 1] == 'x') {
        answer.emplace_back(0);
    }
    
    return answer;
}
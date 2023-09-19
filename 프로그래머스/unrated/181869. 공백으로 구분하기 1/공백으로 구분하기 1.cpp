#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    string str;
    istringstream ss(my_string);
    
    while (ss >> str) {
        answer.emplace_back(str);
    }
    
    return answer;
}
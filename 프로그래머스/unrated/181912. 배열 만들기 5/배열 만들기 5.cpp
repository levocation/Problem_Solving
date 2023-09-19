#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    
    string temp;
    
    for (int i = 0; i < intStrs.size(); i++) {
        temp = "";
        temp = intStrs[i].substr(s, l);
        if (stoi(temp) > k) {
            answer.emplace_back(stoi(temp));
        }
    }
    
    return answer;
}
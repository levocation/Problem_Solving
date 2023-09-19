#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    string temp;
    
    for (int i = 0; i < strArr.size(); i++) {
        temp = "";
        
        for (int j = 0; j < strArr[i].size(); j++) {
            if (i % 2 == 0) {
                temp += tolower(strArr[i][j]);
            } else {
                temp += toupper(strArr[i][j]);
            }
        }
        
        answer.emplace_back(temp);
    }
    
    return answer;
}
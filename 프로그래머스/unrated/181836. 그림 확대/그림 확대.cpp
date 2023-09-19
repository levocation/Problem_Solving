#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    
    string temp;
    
    for (int i = 0; i < picture.size(); i++) {
        temp = "";
        for (int j = 0; j < picture[i].length(); j++) {
            for (int t = 0; t < k; t++) {
                temp += picture[i][j];
            }
        }
       for (int t = 0; t < k; t++) {
            answer.emplace_back(temp);
       }
    }
    
    return answer;
}
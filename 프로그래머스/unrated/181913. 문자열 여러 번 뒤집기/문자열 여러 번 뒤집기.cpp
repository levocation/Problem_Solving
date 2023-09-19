#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = my_string;
    string t = answer;
    
    int startPos = -1;
    int endPos = -1;
    
    for (int i = 0; i < queries.size(); i++) {
        startPos = queries[i][0];
        endPos = queries[i][1];
        for (int j = 0; j < endPos - startPos + 1; j++) {
            t[startPos + j] = answer[endPos - j];
        }
        answer = t;
    }
    
    return answer;
}
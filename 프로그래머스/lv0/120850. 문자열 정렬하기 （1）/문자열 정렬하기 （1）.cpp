#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    for (char ch : my_string) {
        if (ch - '0' < 10) {
            answer.emplace_back((int)(ch - '0'));
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
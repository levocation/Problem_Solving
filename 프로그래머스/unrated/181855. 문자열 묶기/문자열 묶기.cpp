#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    int max = -1;
    
    map<int, int> m; // <문자열 길이, 개수>
    
    for (string str : strArr) {
        if (m.find(str.length()) == m.end()) {
            m.insert({str.length(), 1});
        } else {
            m.find(str.length())->second += 1;
        }
    }
    
    for (auto iter : m) {
        if ((iter.second) >= max) {
            answer = iter.first;
            max = iter.second;
        } 
    }
    
    return max;
}
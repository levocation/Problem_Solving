#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    map<char, int> m;
    
    for (char ch : my_string) {
        if (m.find(ch) == m.end()) {
            m.insert({ch, 1});
            answer += ch;
        }
    }
    
    return answer;
}
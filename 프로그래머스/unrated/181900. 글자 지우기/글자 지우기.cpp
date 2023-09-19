#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = my_string;
    string t = "";
    vector<char> cv;
    
    for (int i : indices) {
        answer[i] = ' ';
    }
    
    for (char ch : answer) {
        if (ch != ' ') {
            cv.emplace_back(ch);
        }
    }
    
    for (char ch : cv) {
        t += ch;
    }
    
    answer = t;
    
    return answer;
}
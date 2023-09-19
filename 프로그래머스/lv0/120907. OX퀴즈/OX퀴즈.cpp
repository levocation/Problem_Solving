#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    int a, b, c;
    string op;
    string buffer;
    
    for (int i = 0; i < quiz.size(); i++) {
        stringstream ss(quiz[i]);
        getline(ss, buffer, ' ');
        a = stoi(buffer);
        getline(ss, buffer, ' ');
        op = buffer;
        getline(ss, buffer, ' ');
        b = stoi(buffer);
        getline(ss, buffer, ' '); // '='이 조회되므로 한 턴 스킵
        getline(ss, buffer, ' ');
        c = stoi(buffer);
        
        if (op == "+") {
            answer.emplace_back(a + b == c ? "O" : "X");
        } else if (op == "-") {
            answer.emplace_back(a - b == c ? "O" : "X");
        }
    }
    
    return answer;
}
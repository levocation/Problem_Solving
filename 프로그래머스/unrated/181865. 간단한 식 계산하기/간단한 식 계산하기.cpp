#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    
    stringstream ss(binomial);
    string buffer;
    
    int a = 0, b = 0;
    string op;
    
    getline(ss, buffer, ' ');
    a = stoi(buffer);
    getline(ss, buffer, ' ');
    op = buffer;
    getline(ss, buffer, ' ');
    b = stoi(buffer);
    
    if (op == "+") {
        return a + b;
    } else if (op == "-") {
        return a - b;
    } else if (op == "*") {
        return a * b;
    } else if (op == "/") {
        return a / b;
    }
    
    return answer;
}
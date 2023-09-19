#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    int answer = 0;
    
    string op = ineq + eq;
    
    if (op == "<=") {
        answer = (n <= m) ? 1 : 0;
    } else if (op == "<!") {
        answer = (n < m) ? 1 : 0;
    } else if (op == ">=") {
        answer = (n >= m) ? 1 : 0;
    } else if (op == ">!") {
        answer = (n > m) ? 1 : 0;
    }
    
    return answer;
}
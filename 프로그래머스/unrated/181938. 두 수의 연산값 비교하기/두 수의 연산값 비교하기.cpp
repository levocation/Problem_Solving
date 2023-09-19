#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int str[2] = {
        stoi(to_string(a) + to_string(b)),
        2 * a * b
    };
    
    if (str[0] > str[1]) {
        answer = str[0];
    } else {
        answer = str[1];
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    
    string n = to_string(num);
    
    if (n.find(to_string(k)) == string::npos) {
        answer = -1;
    } else {
        answer = n.find(to_string(k)) + 1;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (answer = 1; (answer * 6) % n != 0; answer++) {}
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (answer = 1; n % answer != 1; answer++) {}
    
    return answer;
}
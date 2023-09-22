#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    int max = (a > b ? a : b);
    int min = a + b - max;
    
    for (int i = min; i <= max; i++) {
        answer += i;
    }
    
    return answer;
}
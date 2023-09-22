#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    double sq = sqrt(n);
    
    if (sq == (int)sq) {
        answer = (sq + 1) * (sq + 1);
    } else {
        answer = -1;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int count = 0;
    if (a % 2 == 1) count++;
    if (b % 2 == 1) count++;
    
    switch (count) {
        case 2:
            answer = (a * a) + (b * b);
            break;
        case 1:
            answer = 2 * (a + b);
            break;
        case 0:
            answer = abs(a - b);
            break;
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    int answer = 0;
    
    if (a == b && b == c && c == a) { // 세 숫자가 모두 같음
        answer = (a + b + c) * (a * a + b * b + c * c) * (a * a * a + b * b * b + c * c * c);
    } else if (a != b && b != c && c != a) { // 세 숫자가 모두 다름
        answer = a + b + c;
    } else {
        answer = (a + b + c) * (a * a + b * b + c * c);
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    int gcd = 1; // gcd(a, b)
    
    int div_a = 0; // a를 gcd(a, b)로 나눈 값
    int div_b = 0; // b를 gcd(a, b)로 나눈 값
    
    for (int i = (a > b ? a : b); i >= 1; i--) {
        // a와 b중 더 큰 수   부터 1까지
        if (a % i == 0 && b % i == 0) {
            // 순회 중인 값이 a랑 b 둘 다 나누어떨어지면
            
            gcd = i;
            // 그것이 최대공약수이다.
            
            break;
        }
    }
    
    div_a = a / gcd; // 분자
    div_b = b / gcd; // 분모 (실질적으로 중요한 것)
    
    while (div_b / 2 == (div_b / 2.0)) {
        div_b /= 2;
    }
    
    while (div_b / 5 == (div_b / 5.0)) {
        div_b /= 5;
    }
    
    if (div_b == 1) {
        answer = 1;
    } else {
        answer = 2;
    }
    
    return answer;
}

#include <string>
#include <vector>

using namespace std;

int odd(int num) {
    return num / 2 + 1;
}

int even(int num) {
    return (num + 1);
}

int solution(int n) {
    
    /*
    n % 2 == 1 이라면 (n이 홀수)
    
    어떤 수 n을 a에 대한 합으로 나타내면
    a = n 이라고 볼 수 있다.
    
    n을 15라고 가정.
    
    a의 평균값은 a
    ==> a = 15
    
    (a - 1) + a + (a + 1) = 15 면 
    (a - 1) + a + (a + 1) 의 평균값은 a
    ==> (2 * 1 + 1)a = 15
    
    (a - z) + (a - (z - 1)) + ... 
    + a + (a + 1) + ... + (a + z)의 평균값이 15 면
    (a - z) + (a - (z - 1)) + ... 
    + a + (a + 1) + ... + (a + z) 의 평균값은 a
    ==> (2z + 1)a = 15
    
    (a - z) + (a - (z - 1)) + ... 
    + a + (a + 1) + ... + (a + z)의 평균값이 n 면
    (a - z) + (a - (z - 1)) + ... 
    + a + (a + 1) + ... + (a + z) 의 평균값은 a
    ==> (2z + 1)a = n
    
    즉, n이 a의 배수라면
    n은 a를 평균값으로 하여 자연수의 합으로 나타낼 수 있다.
    
    n % 2 == 0 일 때,
    
    a + (a + 1) = 15
    2a + 1 = 16
    
    (a - 1) + a + (a + 1) + (a + 2) = 15
    4a + 2 = 16
    
    (a - z) + (a - (z - 1)) + ...
    + a + (a + 1) + ... + (a + z + 1) = 15
    
    2(z + 1)a + (z + 1) = 15
    (2a + 1)(z + 1) = 15
    
    (2a + 1)(z + 1) = n
    */
    
    int answer = 0;
    
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            // 홀수
            if (n % i == 0) answer++;
        } else {
            // 짝수
            
        }
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

long long fibo(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (fibo(n - 1) % 1234567) + (fibo(n - 2) % 1234567);
}
// 위처럼 재귀함수로 처리하면
// 오버플로우가 날 수도 있고,
// 시간 초과가 발생할 수도 있다.

int solution(int n) {
    int answer = 0;
    
    int* dp = new int[1234567];
    
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            dp[i] = 0;
        } else if (i == 1) {
            dp[i] = 1;
        } else {
            dp[i] = (dp[i - 1] % 1234567) + (dp[i - 2] % 1234567) % 1234567;
            // 나머지 연산의 성질
            // (A + B) % m = ((A % m) + (B % m)) % m
            
            // 증명
            // A = q1 * m + r1;
            // B = q2 * m + r2;
            // (A + B) % m
            // = (q1 * m + r1 + q2 * m + r2) % m
            // = ((q1 + q2) * m + r1 + r2) % m .... ①
            // 이때 % m은 나머지 연산이므로
            // ((q1 + q2) * m) % m = 0 이 성립하기 때문에
            // ① = (r1 + r2) % m
            // 여기서 r1과 r2는 각각
            // r1 = A % m, r2 = B % m 이므로
            // (A + B) % m = ((A % m) + (B % m)) % m
        }
    }
    
    answer = dp[n] % 1234567;
    
    return answer;
}
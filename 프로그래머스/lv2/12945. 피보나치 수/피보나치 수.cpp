#include <string>
#include <vector>

using namespace std;

long long fibo(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (fibo(n - 1) % 1234567) + (fibo(n - 2) % 1234567);
}

int solution(int n) {
    int answer = 0;
    
    int* dp = new int[1234567];
    
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            dp[i] = 0;
        } else if (i == 1) {
            dp[i] = 1;
        } else {
            dp[i] = (dp[i - 1] % 1234567) + (dp[i - 2] % 1234567);
        }
    }
    
    answer = dp[n] % 1234567;
    
    return answer;
}
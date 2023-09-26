#include <string>
#include <vector>

using namespace std;

int cola(int a, int b, int n) {
    if (a > n) return 0;
    return (n / a) * b + cola(a, b, (n / a) * b + (n % a));
}

int solution(int a, int b, int n) {
    int answer = cola(a, b, n);
    return answer;
}
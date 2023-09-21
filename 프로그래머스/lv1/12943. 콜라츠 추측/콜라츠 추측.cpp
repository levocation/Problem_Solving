#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int i = 0;
    
    long long n = num;
    
    for (i = 0; n != 1 && i <= 500; i++) {
        if (n % 2 == 0) n /= 2;
        else n = (n * 3) + 1;
    }
    
    if (i > 500) {
        answer = -1;
    } else {
        answer = i;
    }
    
    return answer;
}
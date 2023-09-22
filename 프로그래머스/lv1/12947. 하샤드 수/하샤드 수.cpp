#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int n = x;
    int hap = 0;
    
    while (n != 0) {
        hap += n % 10;
        n /= 10;
    }
    
    answer = (x % hap == 0);
    
    return answer;
}
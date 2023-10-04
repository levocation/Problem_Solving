#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int temp = n;
    int binary_n_one_count = 0;
    
    while (temp != 0) {
        binary_n_one_count += (temp % 2);
        temp /= 2;
    }
    
    int one_count = 0;
    
    for (int i = n + 1; ; i++) {
        temp = i;
        one_count = 0;
        
        while (temp != 0) {
            one_count += (temp % 2);
            temp /= 2;
        }
        
        if (binary_n_one_count == one_count) {
            answer = i;
            break;
        }
    }
    
    return answer;
}
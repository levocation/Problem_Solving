#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int num = n;
    int i = 0;
    
    bool is_division = false;
    
    for (i = 2; num != 1; i += 0) {
        if (num % i == 0) {
            num = num / i;
            is_division = true;
        } else {
            if (is_division) {
                answer.emplace_back(i);
                is_division = false;
            }
            i++;
        }
    }
    
    if (is_division) {
        answer.emplace_back(i);
    }
    
    return answer;
}
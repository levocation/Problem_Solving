#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    
    vector<int> answer(right - left + 1, 0);
    
    for (long long i = 0; i < right - left + 1; i++) {
        answer[i] = ((i + left) / n > (i + left) % n 
                            ? (i + left) / n + 1 
                            : (i + left) % n + 1);
    }
    return answer;
}
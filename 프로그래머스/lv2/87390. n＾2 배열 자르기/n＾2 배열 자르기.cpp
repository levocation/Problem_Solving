#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    
    vector<int> answer;
    
    for (long long i = 0; i < right - left + 1; i++) {
        answer.emplace_back((i + left) / n > (i + left) % n 
                            ? (i + left) / n + 1 
                            : (i + left) % n + 1);
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    for (int i = 0; n != 0; i++) {
        answer.emplace_back(n % 10);
        n /= 10;
    }
    
    return answer;
}
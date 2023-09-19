#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    answer.emplace_back(n);
    
    while (*(answer.end() - 1) != 1) {
        if (*(answer.end() - 1) % 2 == 0) {
            answer.emplace_back(*(answer.end() - 1) / 2);
        } else {
            answer.emplace_back(*(answer.end() - 1) * 3 + 1);
        }
    }
    
    return answer;
}
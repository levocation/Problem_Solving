#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int k) {
    vector<int> answer;
    
    for (int i = 1; ; i++) {
        if (i * k > n) {
            break;
        } else {
            answer.emplace_back(i * k);
        }
    }
    
    return answer;
}
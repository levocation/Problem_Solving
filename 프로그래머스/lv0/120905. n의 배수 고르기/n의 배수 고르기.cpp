#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    
    for (int i : numlist) {
        if (i % n == 0) {
            answer.emplace_back(i);
        }
    }
    
    return answer;
}
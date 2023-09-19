#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer = arr;
    
    for (int i = 0; i < answer.size(); i++) {
        if (k % 2 == 1) {
            answer[i] *= k;
        } else {
            answer[i] += k;
        }
    }
    
    return answer;
}
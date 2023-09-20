#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer = numbers;
    
    int temp;
    
    if (direction == "left") {
        temp = answer[0];
        for (int i = 1; i < answer.size(); i++) {
            answer[i-1] = answer[i];
        }
        answer[answer.size() - 1] = temp;
    } else if (direction == "right") {
        temp = answer[answer.size() - 1];
        for (int i = answer.size() - 1; i >= 1; i--) {
            answer[i] = answer[i - 1];
        }
        answer[0] = temp;
    }
    
    return answer;
}
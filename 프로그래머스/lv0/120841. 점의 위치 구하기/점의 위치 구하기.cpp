#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    int answer = 0;
    
    if (dot[0] * dot[1] > 0) {
        answer++;
    } else {
        answer += 2;
    }
    
    if (dot[1] < 0) {
        answer += 2;
    }
    
    return answer;
}
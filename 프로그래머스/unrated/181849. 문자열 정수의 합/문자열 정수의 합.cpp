#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    
    for (char ch : num_str) {
        answer += (int)(ch - 48);
    }
    
    return answer;
}
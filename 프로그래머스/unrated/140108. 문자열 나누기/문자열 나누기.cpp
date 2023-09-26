#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int count[2] = {1, 0};
    
    char key = s[0];
    
    for (int i = 1; i < s.length(); i++) {
        count[s[i] != key]++;
        if (count[0] == count[1]) {
            answer++;
            count[0] = 0;
            count[1] = 0;
            key = s[i+1];
        }
    }
    
    answer += (count[0] != count[1]);
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    int answer = n;
    
    for (char ch : control) {
        switch (ch) {
            case 'w':
                answer++;
                break;
            case 's':
                answer--;
                break;
            case 'd':
                answer += 10;
                break;
            case 'a':
                answer -= 10;
                break;
            default:
                break;
        }
    }
    
    return answer;
}
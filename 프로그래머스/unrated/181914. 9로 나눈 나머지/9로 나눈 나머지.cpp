#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    int answer = 0;
    
    for (char ch : number) {
        answer += (int)(ch - 48);
    }
    
    
    return answer % 9;
}
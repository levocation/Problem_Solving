#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 0;
    
    for (answer = 1; answer * slice < n; answer++) {}
    
    return answer;
}
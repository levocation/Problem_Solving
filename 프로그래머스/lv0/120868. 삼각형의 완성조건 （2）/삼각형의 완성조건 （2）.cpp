#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    int long_line = (sides[0] > sides[1] ? sides[0] : sides[1]);
    int short_line = sides[0] + sides[1] - long_line;
    
    answer += short_line;
    // 가장 긴 변이 long_line일 경우
    // long_line과 나머지 한 변의 길이가 같을 때도 성립한다.
    // ex. (5, 5, 3)
    
    answer += (short_line - 1);
    // 가장 긴 변이 나머지 한 변일 경우
    
    return answer;
}
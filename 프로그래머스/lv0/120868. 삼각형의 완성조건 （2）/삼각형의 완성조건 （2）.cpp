#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    int long_line = (sides[0] > sides[1] ? sides[0] : sides[1]);
    // 두 변 중 더 긴 변의 길이
    
    int short_line = sides[0] + sides[1] - long_line;
    // 두 변 중 더 짧은 변의 길이 = (긴 변 + 짧은 변) - 긴 변
    
    // 이하 주석에서 long_line = l, short_line = s,
    // 구해야 하는 나머지 한 변을 x라고 칭한다.
    
    answer += short_line;
    // 가장 긴 변이 l일 경우
    // 세 변이 각각 (l, x, s) 이라면
    
    // 가장 긴 변은 나머지 두 변의 합보다 작다
    // l < x + s 
    // l - s < x        ..... ①
    
    // l이 가장 긴 변이므로 x는 l보다 크지 않다.
    // x ≤ l            ..... ②
    
    // ①과 ②를 합치면
    // l - s < x ≤ l
    // l, s, x가 자연수이므로
    // l - s + 1 ≤ x ≤ l
    
    // a ≤ x ≤ b 라고 할 때
    // x의 개수 = b - a + 1
    // 이 식을 위에 대입하면
    // x의 개수 = l - (l - s + 1) + 1
    // = l - l + s - 1 + 1
    // = s
    
    answer += (short_line - 1);
    // 가장 긴 변이 x일 경우
    // 세 변이 각각 (l, x, s) 이라면
    
    // 가장 긴 변은 나머지 두 변의 합보다 작다
    // x < l + s        ..... ①       
    
    // x가 가장 긴 변이므로 l은 x보다 크지 않다.
    // 그러나 위에서 이미 x = l일 때를 다뤘기 때문에
    // x > l            ..... ②
    
    // ①과 ②를 합치면
    // l < x < l + s
    // l, s, x가 자연수이므로
    // l + 1 ≤ x < l + s
    // l + 2 ≤ x + 1 ≤ l + s + 1
    
    // x + 1의 개수 = l + s + 1 - (l + 2) + 1
    // = l + s + 1 - l - 2 + 1
    // = l - l + s + 1 - 2 + 1
    // = s
    // x + 1의 개수 = s 이므로
    // x의 개수 = s - 1
    
    return answer;
}
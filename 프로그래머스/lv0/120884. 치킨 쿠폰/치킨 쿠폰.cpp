#include <string>
#include <vector>

using namespace std;

int loop(int chicken) {
    int answer = 0;
    int chicken_count = chicken;
    int coupon = 0;
    
    // 매 회전마다 치킨 개수의 일의 자리를 없앰(1081, 108, 10, 1, ...)
    for (; chicken_count > 0; chicken_count /= 10) {
        
        answer += chicken_count / 10;
        // 치킨 10마리당 서비스 치킨 1마리
        // 치킨 10 * n마리당 서비스 치킨 n마리
        
        coupon += chicken_count % 10;
        // 치킨을 주문하고 남은 쿠폰의 개수
    }
    
    // 남은 쿠폰의 개수가 10개 이상이라면
    if (coupon >= 10) {
        // 치킨 10마리 주문 == 서비스 치킨 1마리
        // 쿠폰 10장으로 주문 == 서비스 치킨 1마리
        // 이를 통해 치킨 계산식에 쿠폰 개수를 넣으면 된다.
        // 그러나 쿠폰으로 시킨 서비스 치킨의 쿠폰을 긁어모아서
        // 또 서비스 치킨을 시켜먹을 수 있으므로
        // 이를 재귀를 통해 처리한다.
        return answer + loop(coupon);
    } else {
        // 쿠폰이 9장 이하라면 그냥 치킨의 개수를 리턴
        return answer;
    }
    
}

int solution(int chicken) {
    
    // 소스코드 요약
    // 서비스 치킨은 [치킨 10마리 주문] 또는 [쿠폰 10장] 당 1마리 이므로
    // 주문한 치킨의 서비스 치킨의 개수를 센 뒤
    // 쿠폰으로 주문 가능한 서비스 치킨의 개수를 더한다.
    
    return loop(chicken);
}
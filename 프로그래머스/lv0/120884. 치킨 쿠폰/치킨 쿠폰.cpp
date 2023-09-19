#include <string>
#include <vector>

using namespace std;

int loop(int chicken) {
    int answer = 0;
    int chicken_count = chicken;
    int coupon = 0;
    
    for (; chicken_count > 0; chicken_count /= 10) {
        answer += chicken_count / 10;
        coupon += chicken_count % 10;
    }
    
    if (coupon >= 10) {
        return answer + loop(coupon);
    } else {
        return answer;
    }
    
}

int solution(int chicken) {
    return loop(chicken);
}
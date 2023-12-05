#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    vector<int> knight_list;
    // 기사의 번호
    
    vector<int> divisor_list(number, 1);
    // 기사별 약수의 개수
    
    int count = 0;
    
    for (int i = 1; i <= number; i++) {
        knight_list.emplace_back(i);
    }
    
    for (int i = 0; i < number; i++) {
        for (int j = 2; j <= knight_list[i]; j++) {
            count = 0;
            while (knight_list[i] % j == 0) {
                knight_list[i] /= j;
                count++;
            }
            divisor_list[i] *= (count + 1);
        }
        
        if (divisor_list[i] > limit) {
            divisor_list[i] = power;
        }
        
        answer += divisor_list[i];
    }
    
    return answer;
}
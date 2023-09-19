#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    
    // 로직 요약
    // 평균값을 구한 배열을 따로 만들어서
    // 그 배열에서 순위를 매긴다.
    // 배열이 정렬되어있지 않으므로
    // 가장 단순한 항목 비교(Comparison-Based) 방식을 사용하여
    // 시간 복잡도는 O(n²) 이다.
    
    vector<int> answer;
    
    vector<double> avg;
    // (20점 + 5점) / 2 = 12.5 이므로
    // 이같은 소수점을 처리하기 위해 double vector로 선언
    
    for (int i = 0; i < score.size(); i++) {
        avg.emplace_back((score[i][0] + score[i][1]) / 2.0);
        // 평균값을 구하기
        
        answer.emplace_back(1);
        // 순위 구하기 로직
        // 배열이 정렬되어있지 않은 상태에서 순위를 구해야 하므로
        // 항목 비교 방식을 사용한다.
        // 처음엔 모두가 1등이라고 가정한 상태에서
        // 항목 비교를 통해 순위를 조정한다.
    }
    
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer.size(); j++) {
            // O(n²)
            if (avg[i] > avg[j]) {
                // avg[i]라는 기준 값에
                // avg[j]를 전부 비교해서
                // avg[j]가 더 작다면
                // 해당 인덱스에 해당하는 순위(answer[j])
                // 의 값을 1 늘린다.
                // 이를 반복하면 순위가 매겨진다.
                answer[j]++;
            }
        }
    }
    
    return answer;
}
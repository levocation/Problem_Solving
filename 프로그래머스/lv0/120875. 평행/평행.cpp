#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    
    // 풀이 요약
    // 점의 개수가 4개로 고정이므로
    // 가능한 경우의 수는 3가지라는 것을 파악하여
    // [1, 2] / [3, 4]
    // [1, 3] / [2, 4]
    // [1, 4] / [2, 3]
    // 위 3가지의 기울기를 서로 비교하여 하나라도 같다면
    // 평행한 선이 있는 것이다.
    
    int answer = 0;
    
    double value = 0.0;
    
    vector<bool> v;
    
    v.emplace_back(
        ((double)(dots[0][1] - dots[1][1]) 
        / (double)(dots[0][0] - dots[1][0]))
        ==
        (double)(dots[2][1] - dots[3][1]) 
        / (double)(dots[2][0] - dots[3][0])
    );
    // v.emplace_back(
    // ((y1 - y2) / (x1 - x2)) == ((y3 - y4) / (x3 - x4))
    //)
    
    v.emplace_back(
        ((double)(dots[0][1] - dots[2][1]) 
        / (double)(dots[0][0] - dots[2][0]))
        ==
        (double)(dots[1][1] - dots[3][1]) 
        / (double)(dots[1][0] - dots[3][0])
    );
    // v.emplace_back(
    // ((y1 - y3) / (x1 - x3)) == ((y2 - y4) / (x2 - x4))
    //)
    
    v.emplace_back(
        ((double)(dots[0][1] - dots[3][1]) 
        / (double)(dots[0][0] - dots[3][0]))
        ==
        (double)(dots[1][1] - dots[2][1]) 
        / (double)(dots[1][0] - dots[2][0])
    );
    // v.emplace_back(
    // ((y1 - y4) / (x1 - x4)) == ((y2 - y3) / (x2 - x3))
    //)
    
    answer = v[0] || v[1] || v[2];
    
    return answer;
}
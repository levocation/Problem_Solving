#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    // 풀이 요약
    // 두 수를 곱한 것의 합의 최대를 만들려면
    // 기하평면에 의거하여 sqrt(a²) = ab, a = b
    // 즉 a와 b의 차잇값이 작아질 수록 그 값이 커지므로
    // 합의 최소를 만들려면 a와 b의 차잇값이 커져야 한다.
    // 즉, 집합 A와 B가 있을 때
    // A의 원소에서 가장 작은 값과
    // B의 원소에서 가장 큰 값을 곱한 후 모두 더하면
    // 그것이 최솟값이다.
    
    int answer = 0;
    
    sort(A.begin(), A.end());
    // 오름차순 정렬
    
    sort(B.begin(), B.end(), greater<>());
    // 내림차순 정렬
    
    for (int i = 0; i < A.size(); i++) {
        answer += A[i] * B[i];
    }
    
    return answer;
}
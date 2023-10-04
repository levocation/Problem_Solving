#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> elements) {
    // 완전탐색 방식으로 풀었기 때문에 시간이 오래 걸림.
    int answer = 0;
    
    int sum = 0;
    // 부분수열의 합을 임시로 담아두는 변수
    
    map<int, bool> m;
    
    for (int i = 1; i < elements.size(); i++) {
        // 어느 경우에도 맨 마지막(모든 값을 더하는 경우의 수)
        // 는 1가지 뿐이므로 배제.
        for (int j = 0; j < elements.size(); j++) {
            // 맨 마지막 경우의 수를 제외하고
            // 전부 elements.size() 만큼의 경우의 수가 나온다.
            sum = 0;
            for (int k = 0; k < i; k++) {
                // 길이가 i인 연속 부분 수열을 추출한다는 뜻
                sum += elements[(j + k) % elements.size()];
            }
            
            if (m.find(sum) == m.end()) {
                m.insert({sum, true});
                answer++;
            }
            
        }
    }
    
    sum = 0;
    for (int i = 0; i < elements.size(); i++) {
        sum += elements[i];
    }
    
    if (m.find(sum) == m.end()) {
        m.insert({sum, true});
        answer++;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    int count = 0;
    
    int tmp = 0;
    
    while (pq.top() < K) {
        if (pq.size() < 2) {
            answer = -1;
            break;
        }
        tmp = pq.top();
        pq.pop();
        
        tmp += pq.top() * 2;
        
        pq.pop();
        pq.push(tmp);
        
        answer++;
    }
    
    return answer;
}
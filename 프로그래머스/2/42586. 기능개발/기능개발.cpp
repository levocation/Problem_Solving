#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int pop_count = 0;
    
    while (progresses.size() != 0) {
        if (progresses.front() >= 100) {
            pop_count++;
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            continue;
        } else {
            if (pop_count != 0) {
                answer.emplace_back(pop_count);
            }
            pop_count = 0;
            
            for (int i = 0; i < progresses.size(); i++) {
                progresses[i] += speeds[i];
            }
        }
    }
    
    if (pop_count != 0) {
        answer.emplace_back(pop_count);
    }
    
    return answer;
}
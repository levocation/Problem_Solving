#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int count = 1;
    int tmp = 0;
    int idx_tmp = 0;
    
    map<int, int> m;
    
    vector<int> sort_priorities = priorities;
    vector<int> index_priorities;
    
    for (int i = 0; i < priorities.size(); i++) {
        index_priorities.emplace_back(i);
    }
    
    sort(sort_priorities.begin(), sort_priorities.end(), greater<int>());
    
    while (true) {
        if (priorities[0] == sort_priorities[0]) {
            if (index_priorities[0] == location) {
                answer = count;
                break;
            } else {
                count++;
                priorities.erase(priorities.begin());
                sort_priorities.erase(sort_priorities.begin());
                index_priorities.erase(index_priorities.begin());
            }
        } else {
            tmp = priorities.front();
            priorities.erase(priorities.begin());
            priorities.emplace_back(tmp);
            
            idx_tmp = index_priorities.front();
            index_priorities.erase(index_priorities.begin());
            index_priorities.emplace_back(idx_tmp);
        }
    }
    
    return answer;
}
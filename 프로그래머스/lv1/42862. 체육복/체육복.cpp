#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> count(n, 1);
    
    for (int i : lost) {
        count[i-1]--;
    }
    
    for (int i : reserve) {
        count[i-1]++;
    }
    
    for (int i = 0; i < count.size(); i++) {
        if (count[i] == 2) {
            if (i - 1 >= 0 && count[i-1] == 0) {
                count[i-1]++;
                count[i]--;
            } else if (i + 1 <= count.size() - 1 
                       && count[i+1] == 0) {
                count[i+1]++;
                count[i]--;
            }
        }
    }
    
    for (int i : count) {
        if (i != 0) answer++;
    }
    
    return answer;
}
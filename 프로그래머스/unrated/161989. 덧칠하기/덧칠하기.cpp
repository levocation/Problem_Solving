#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    vector<int> wall(n, 1);
    
    for (int i : section) {
        wall[i-1] = 0;
    }
    
    for (int i = section[0] - 1; i < wall.size(); i++) {
        if (wall[i] == 1) {
            continue;
        } else {
            for (int j = i; j < i + m; j++) {
                if (j >= wall.size()) {
                    break;
                } else {
                    wall[j] = 1;
                }
            }
            i += (m - 1);
            answer++;
        }
    }
    
    return answer;
}
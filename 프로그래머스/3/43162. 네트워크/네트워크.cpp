#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    queue<int> q;
    int cur;
    
    int wh = computers.size();
    
    for (int i = 0; i < wh; i++) {
        if (computers[i][i] == 1) {
            computers[i][i] = -1;
            q.push(i);

            while (!q.empty()) {
                cur = q.front(); q.pop();
                for (int nxt = 0; nxt < wh; nxt++) {
                    if (computers[cur][nxt] == 1) {
                        computers[cur][nxt] = -1;
                        q.push(nxt);
                    }
                }
            }
            answer++;
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

int solution(vector<int> players_list, int m, int k) {
    int answer = 0;
    int server_cnt = 0; // 현재 서버 수
    int required_server_cnt = 0; // 증설이 필요한 서버 수
    queue<pair<int, int>> server_q; // queue<map<서버 수, 서버 생성 시점>>
    
    for (int i = 0; i < players_list.size(); i++) {
        while (!server_q.empty() && server_q.front().second + k == i) {
            server_cnt -= server_q.front().first;
            server_q.pop();
        }
        
        if ((int)(players_list[i] / m) > server_cnt) {
            required_server_cnt = (int)(players_list[i] / m) - server_cnt;
            
            server_cnt += required_server_cnt;
            answer += required_server_cnt;
            
            server_q.push({required_server_cnt, i});
        }
    }
    
    return answer;
}
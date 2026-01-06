import java.util.*;

class Pair {
    public int x;
    public int y;
    
    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        int server_cnt = 0; // 현재 서버 수
        int required_server_cnt = 0; // 증설이 필요한 서버 수
        ArrayDeque<Pair> server_q = new ArrayDeque<>(); // queue<map<서버 수, 서버 생성 시점>>
        
        for (int i = 0; i < players.length; i++) {
            while (!server_q.isEmpty() && server_q.getFirst().y + k == i) {
                server_cnt -= server_q.peek().x;
                server_q.remove();
            }
            
            if ((int)(players[i] / m) > server_cnt) {
                required_server_cnt = (int)(players[i] / m) - server_cnt;

                server_cnt += required_server_cnt;
                answer += required_server_cnt;

                server_q.add(new Pair(required_server_cnt, i));
            }
        }
        
        return answer;
    }
}
import java.util.*;

class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        Queue<Integer> q = new LinkedList<>();
        int cur;
        
        int wh = computers.length;
        
        for (int i = 0; i < wh; i++) {
            if (computers[i][i] == 1) {
                computers[i][i] = -1;
                q.add(i);

                while (!q.isEmpty()) {
                    cur = q.poll();
                    for (int nxt = 0; nxt < wh; nxt++) {
                        if (computers[cur][nxt] == 1) {
                            computers[cur][nxt] = -1;
                            q.add(nxt);
                        }
                    }
                }
                answer++;
            }
        }
        
        return answer;
    }
}
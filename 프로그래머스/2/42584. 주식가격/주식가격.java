import java.util.*;
import java.lang.*;

class Solution {
    static class Pair {
        public int price;
        public int index;
        
        Pair(int x, int y) {
            this.price = x;
            this.index = y;
        }
    }
    public int[] solution(int[] prices) {
        int len = prices.length;
        
        int[] answer = new int[len];
        
        ArrayDeque<Pair> s = new ArrayDeque<>();
        ArrayDeque<Pair> tmp = new ArrayDeque<>();
        
        // insert : offerLast()
        // select : getLast()
        // delete : pollLast()
        
        for (int i = 0; i < len; i++) {
            if (s.isEmpty()) {
                s.offerLast(new Pair(prices[i], i));
                continue;
            }
            
            int target = prices[i];
            
            while (!s.isEmpty() && s.getLast().price > target) {
                tmp.offerLast(s.getLast());
                s.pollLast();
            }
            
            s.offerLast(new Pair(prices[i], i));
            
            while (!tmp.isEmpty()) {
                Pair p = tmp.getLast(); tmp.pollLast();
                answer[p.index] = i - p.index;
            }
        }
            
        while (!s.isEmpty()) {
            tmp.offerLast(s.getLast());
            s.pollLast();
        }
        while (!tmp.isEmpty()) {
            Pair p = tmp.getLast(); tmp.pollLast();
            answer[p.index] = (len - 1) - p.index;
        }
        
        return answer;
    }
}
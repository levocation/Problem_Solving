import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
public class Main {
    static class Pair {
    	long x;
        long y;
        
        Pair(long x, long y) {
        	this.x = x;
            this.y = y;
        }
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());

        long num = Long.parseLong(st.nextToken());
        long target = Long.parseLong(st.nextToken());
        long answer = -1L;
        Pair p = new Pair(0L, 0L); // tmp
        
        ArrayDeque<Pair> deque = new ArrayDeque<>();

        deque.add(new Pair(num, 1L));

        while (!deque.isEmpty()) {
            p = deque.getFirst(); deque.remove();

            if (p.x == target) {
                answer = p.y;
                break;
            }

            if (p.x * 2L <= target) {
                deque.add(new Pair(p.x * 2L, p.y + 1L));
            }
            if (p.x * 10L + 1L <= target) {
                deque.add(new Pair(p.x * 10L + 1L, p.y + 1L));
            }
        }

        System.out.println(answer);
    }
}
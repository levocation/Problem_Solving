import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
public class Main {

    static class Pair {
        public int x;
        public int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        int max = 0, target = 0, answer = 0;

        int[][] arr = new int[n][n];
        int[][] board = new int[n][n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] > max) max = arr[i][j];
                board[i][j] = 0;
            }
        }

        ArrayDeque<Pair> q = new ArrayDeque<>();

        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};

        for (int num = 0; num < max; num++) {
            target = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (arr[i][j] <= num) board[i][j] = -1; // 물에 잠김
                    else { // 물에 잠기지 않음
                        board[i][j] = 0;
                    }
                    //System.out.print("" + board[i][j] + " ");
                }
                //System.out.println();
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 0) {
                        q.push(new Pair(i, j));
                        board[i][j] = 1;
                        target++;
                        while (!q.isEmpty()) {
                            Pair cur = q.getFirst(); q.remove();
                            for (int dir = 0; dir < 4; dir++) {
                                int nx = cur.x + dx[dir];
                                int ny = cur.y + dy[dir];
            
                                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                                if (board[nx][ny] != 0) continue;
            
                                board[nx][ny] = 1;
                                q.push(new Pair(nx, ny));
                            }
                        }
                    }
                }
            }
            //System.out.println("num : " + num + ", target : " + target + ", answer : " + answer);
            if (target > answer) answer = target;
        }
        
        System.out.println(answer);
    }
}
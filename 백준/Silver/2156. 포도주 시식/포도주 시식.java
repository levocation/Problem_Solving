import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        int[] v = new int[n];
        
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(br.readLine());
        }
        
        int[][] dp = new int[n][3];
        int answer = 0;
        
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i][1] = v[i];
                dp[i][2] = v[i];
            } else if (i == 1) {
                dp[i][1] = v[i];
                dp[i][2] = dp[i-1][1] + v[i];
            } else if (i == 2) {
                dp[i][1] = Math.max(dp[i-2][1], dp[i-2][2]) + v[i];
                dp[i][2] = dp[i-1][1] + v[i];
            } else {
                dp[i][1] = Math.max(Math.max(dp[i-2][1], dp[i-2][2]), Math.max(dp[i-3][1], dp[i-3][2])) + v[i];
                dp[i][2] = dp[i-1][1] + v[i];
            }
            answer = Math.max(answer, Math.max(dp[i][1], dp[i][2]));
        }
        
        System.out.println(answer);
    }
}
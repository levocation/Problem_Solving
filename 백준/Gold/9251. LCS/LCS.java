import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String str1 = br.readLine();
        String str2 = br.readLine();

        int n = str1.length();
        int m = str2.length();
        int answer = 0;
        
        int[][] dp = new int[n + 1][m + 1];

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                dp[i][j] = 0;
            }
        }

        // dp[i][j] : str1의 i번째 문자열을 str2의 j번째 문자열까지 비교했을 때 최장 공통 부분 수열

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
            if (answer < dp[i][m]) answer = dp[i][m];
        }
        
        System.out.println(answer);
    }
}
import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        long answer = 0L;
        
        int[] arr = new int[n + 1];
        arr[0] = 0;

        long[] dp = new long[n + 1];
        dp[0] = 0L;

        int[] cnt_table = new int[m];

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + i;
        }
        
        st = new StringTokenizer(br.readLine());
        
        for (int i = 1; i <= n; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            arr[i] = (arr[i - 1] + tmp) % m;
            cnt_table[arr[i]]++;
        }

        answer += cnt_table[0];
        for (int i = 0; i < m; i++) {
            if (cnt_table[i] == 0) continue;
            answer += dp[cnt_table[i] - 1];
        }

        System.out.println(answer);
    }
}
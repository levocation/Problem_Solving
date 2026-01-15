import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String s = br.readLine();

        int[][] arr = new int[s.length() + 1][26];

        for (int i = 0; i < s.length() + 1; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == 0) arr[i][j] = 0;
                else {
                    if (s.charAt(i - 1) - 'a' == j) arr[i][j] = arr[i - 1][j] + 1;
                    else arr[i][j] = arr[i - 1][j];
                }
            }
        }
        
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            char alp = st.nextToken().charAt(0);
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            bw.write(Integer.toString(arr[y + 1][alp - 'a'] - arr[x][alp - 'a']));
            bw.newLine();
        }

        bw.flush();
    }
}
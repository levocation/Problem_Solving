import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int answer = 0, coefficient = 1, tmp = 0, n = 0;
        String expression = br.readLine();

        expression += "%";
        
        for (int i = 0; i < expression.length(); i++) {
            n = expression.charAt(i) - '0';
            if (n >= 0 && n <= 9) {
                tmp = tmp * 10 + n;
            } else {
                answer += coefficient * tmp;
                tmp = 0;
                if (expression.charAt(i) == '-') coefficient = -1;
            }
        }
        
        System.out.println(answer);
    }
}
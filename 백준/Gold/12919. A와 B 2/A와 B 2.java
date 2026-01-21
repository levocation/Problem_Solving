import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".

public class Main {

    public static boolean isAnswer(String str, String target) {
        if (str.length() == target.length()) {
            if (str.equals(target)) return true;
            return false;
        }

        boolean a1 = false;
        boolean a2 = false;

        if (target.charAt(target.length() - 1) == 'A') {
            a1 = isAnswer(str, target.substring(0, target.length() - 1));
        }
        if (target.charAt(0) == 'B') {
            StringBuffer sb = new StringBuffer(target);
            a2 = isAnswer(str, sb.reverse().toString().substring(0, target.length() - 1));
        }

        return a1 || a2;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String str = br.readLine();
        String target = br.readLine();

        boolean answer = isAnswer(str, target);

        if (answer) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }
    }
}
import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        //StringTokenizer st = new StringTokenizer(br.readLine());

        String target = "";
        boolean isGoodList = false;

        int cnt = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < cnt; i++) {
            int c = Integer.parseInt(br.readLine());

            ArrayList<String> list = new ArrayList<>();

            for (int j = 0; j < c; j++) {
                list.add(br.readLine());
            }

            Collections.sort(list);
            target = "--";
            isGoodList = true;
            
            for (int j = 0; j < c; j++) {
                if (list.get(j).startsWith(target)) {
                    isGoodList = false;
                    break;
                }
                target = list.get(j);
            }

            if (isGoodList) bw.write("YES\n");
            else bw.write("NO\n");
        }

        bw.close();
    }
}
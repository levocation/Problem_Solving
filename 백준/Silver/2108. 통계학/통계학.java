import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        double sum = 0;
        int min = 2147483647;
        int max = -2147483648;
        int most = 0;
        int choibin = 0;
        
        int[] arr = new int[n];

        int[] board = new int[8002];

        List<Integer> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            sum += arr[i];
            if (arr[i] < min) min = arr[i];
            if (arr[i] > max) max = arr[i];

            board[arr[i] + 4000]++;
            if (board[arr[i] + 4000] > most) most = board[arr[i] + 4000];
        }

        Arrays.sort(arr);

        for (int i = 0; i < 8002; i++) {
            if (board[i] == most) list.add(i - 4000);
        }

        if (list.size() > 1) {
            choibin = list.get(1);
        } else {
            choibin = list.get(0);
        }

        System.out.println(Math.round(sum / n));
        System.out.println(arr[n / 2]);
        System.out.println(choibin);
        System.out.println(max - min);

        
    }
}
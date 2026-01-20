import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
public class Main {

    public static int oppositeDir(int dir) {
        int result = dir - 2;
        if (result < 0) result += 4;
        return result;
    }

    public static int rotateCounterclockwise(int dir) {
        int result = dir - 1;
        if (result < 0) result += 4;
        return result;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int height = Integer.parseInt(st.nextToken());
        int width = Integer.parseInt(st.nextToken());
        int answer = 0;

        st = new StringTokenizer(br.readLine());

        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        int[][] board = new int[height][width];

        for (int i = 0; i < height; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < width; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        // 북, 동, 남, 서
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};

        // -1 : 청소된 칸, 0 : 빈 칸, 1 : 벽
        while (true) {
            // 현재 칸이 아직 청소되지 않은 경우
            if (board[x][y] == 0) {
                // 현재 칸을 청소한다.
                board[x][y] = -1;
                answer++;
                continue;
            }

            // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는지 확인
            boolean canCleaningSpace = false;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= height || ny < 0 || ny >= width) continue;
                if (board[nx][ny] != 0) continue;
                canCleaningSpace = true;
                break;
            }

            // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
            if (canCleaningSpace) {
                // 반시계 방향으로 90도 회전한다.
                d = rotateCounterclockwise(d);

                int nx = x + dx[d];
                int ny = y + dy[d];

                // 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우
                if (nx < 0 || nx >= height || ny < 0 || ny >= width) continue;
                if (board[nx][ny] != 0) continue;
                
                // 한 칸 전진한다
                x = nx;
                y = ny;
            } else { // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
                // 바라보는 방향의
                int oppoDir = oppositeDir(d);

                int nx = x + dx[oppoDir];
                int ny = y + dy[oppoDir];

                // 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
                if (nx < 0 || nx >= height || ny < 0 || ny >= width) break;
                if (board[nx][ny] == 1) break;

                // 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진
                x = nx;
                y = ny;
            }
        }


        
        System.out.println(answer);
    }
}
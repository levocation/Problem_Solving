import java.io.*;
import java.util.*;

public class Main {

    static class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int height = Integer.parseInt(st.nextToken());
        int width  = Integer.parseInt(st.nextToken());

        char[][] map = new char[height][width];
        List<Pair> posList = new ArrayList<>();

        for (int i = 0; i < height; i++) {
            String line = br.readLine();
            for (int j = 0; j < width; j++) {
                char c = line.charAt(j);
                map[i][j] = c;
                if (c == 'L') {
                    posList.add(new Pair(i, j));
                }
            }
        }

        int answer = 0;
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};

        // 각 L 지점에서 BFS
        for (Pair p : posList) {

            int[][] dist = new int[height][width];
            ArrayDeque<Pair> q = new ArrayDeque<>();

            q.add(new Pair(p.x, p.y));
            dist[p.x][p.y] = 1;

            while (!q.isEmpty()) {
                Pair cur = q.poll();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];

                    if (nx < 0 || nx >= height || ny < 0 || ny >= width) continue;
                    if (map[nx][ny] != 'L') continue;
                    if (dist[nx][ny] != 0) continue;

                    dist[nx][ny] = dist[cur.x][cur.y] + 1;
                    q.add(new Pair(nx, ny));

                    if (dist[nx][ny] > answer) {
                        answer = dist[nx][ny];
                    }
                }
            }
        }

        System.out.println(answer - 1);
    }
}

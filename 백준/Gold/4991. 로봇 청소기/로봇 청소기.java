import java.io.*;
import java.util.*;

public class Main {
    static int w, h;
    static char[][] m;
    static int[][] dirtyId;
    static boolean[][][] visited;
    static int curX, curY;
    static int dirtyCount;

    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};

    static boolean range(int x, int y) {
        return x >= 0 && x < h && y >= 0 && y < w;
    }

    static int bfs() {
        visited[curX][curY][0] = true;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{curX, curY, 0, 0}); // x, y, mask, dist

        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1], mask = cur[2], dist = cur[3];

            if (mask == (1 << dirtyCount) - 1) {
                return dist;
            }

            for (int i=0;i<4;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!range(nx, ny)) continue;
                if (m[nx][ny] == 'x') continue;

                int newMask = mask;

                if (m[nx][ny] == '*') {
                    int id = dirtyId[nx][ny];

                    // 입력
                    newMask |= (1 << id);
                }

                if (visited[nx][ny][newMask]) continue;
                visited[nx][ny][newMask] = true;
                q.add(new int[]{nx,ny,newMask, dist+1});
            }
        }

        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st;

        while(true) {
            st = new StringTokenizer(br.readLine());
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());

            if (w == 0 && h == 0) break;
            m = new char[h+1][w+1];
            dirtyId = new int[h+1][w+1];
            dirtyCount = 0;

            for (int i=0;i<h;i++) {
                String str = br.readLine();
                for (int j=0;j<w;j++) {
                    m[i][j] = str.charAt(j);

                    if (str.charAt(j) == 'o') {
                        curX = i;
                        curY = j;
                    }

                    if (str.charAt(j) == '*') {
                        dirtyId[i][j] = dirtyCount++;
                    }
                }
            }

            visited = new boolean[h+1][w+1][(int)Math.pow(2, dirtyCount) + 1];

            int res = bfs();
            System.out.println(res);
        }
    }
}

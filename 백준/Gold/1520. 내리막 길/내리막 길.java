import java.io.*;
import java.util.*;

public class Main {

    static int m;
    static int n;
    static int[][] arr;
    static int[][] visited;

    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,1,-1};

    static int dfs(int x, int y) {
        if (x == m - 1 && y == n - 1) return 1;
        if (visited[x][y] != -1) return visited[x][y];

        visited[x][y] = 0;

        for (int i = 0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (arr[x][y] <= arr[nx][ny]) continue;
            visited[x][y] += dfs(nx,ny);
        }

        return visited[x][y];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        arr = new int[m+1][n+1];
        visited = new int[m+1][n+1];

        for (int i=0;i<m;i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0;j<n;j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                visited[i][j] = -1;
            }
        }

        System.out.println(dfs(0,0));


    }
}

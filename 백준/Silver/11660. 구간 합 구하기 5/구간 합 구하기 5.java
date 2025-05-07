import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] arr = new int[n+1][n+1];
        for (int i=1;i<=n;i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=1;j<=n;j++) {
                int num = Integer.parseInt(st.nextToken());
                arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + num;
            }
        }

        for (int i=0;i<m;i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            int res = arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1];
            bw.write(res + "\n");
        }
        bw.flush();
    }

}
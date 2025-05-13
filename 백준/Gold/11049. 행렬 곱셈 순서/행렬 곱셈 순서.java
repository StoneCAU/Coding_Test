import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] r = new int[n+1];
        int[] c = new int[n+1];

        for (int i=1;i<=n;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            r[i] = Integer.parseInt(st.nextToken());
            c[i] = Integer.parseInt(st.nextToken());
        }

        int[][] dp = new int[n+1][n+1];

        for (int len =2;len<=n;len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1;

                dp[i][j] = Integer.MAX_VALUE;
                for (int k = i; k < j; k++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k + 1][j] + r[i] * c[k] * c[j]);
                }
            }
        }

        bw.write(String.valueOf(dp[1][n]));
        bw.flush();
    }
}

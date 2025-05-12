import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());

            int[] arr = new int[n + 1];
            int[] preSum = new int[n + 1];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
                preSum[i] = preSum[i - 1] + arr[i];
            }

            int[][] dp = new int[n + 1][n + 1];

            for (int len = 2; len <= n; len++) { // 구간 길이
                for (int i = 1; i <= n - len + 1; i++) { // 시작점
                    int j = i + len - 1; // 끝점
                    dp[i][j] = Integer.MAX_VALUE;

                    for (int k = i; k < j; k++) {
                        dp[i][j] = Math.min(dp[i][j],
                                dp[i][k] + dp[k + 1][j] + preSum[j] - preSum[i - 1]);
                    }
                }
            }

            bw.write(dp[1][n] + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}

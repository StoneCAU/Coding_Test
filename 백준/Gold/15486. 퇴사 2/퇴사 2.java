import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] t = new int[n + 2];  // n+1까지 필요
        int[] p = new int[n + 2];
        int[] dp = new int[n + 2];  // dp[i]: i일부터 마지막날까지의 최대 수익

        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            t[i] = Integer.parseInt(st.nextToken());
            p[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = n; i >= 1; i--) {
            if (i + t[i] <= n + 1) {
                dp[i] = Math.max(dp[i + 1], p[i] + dp[i + t[i]]);
            } else {
                dp[i] = dp[i + 1];  // 상담 불가일 경우
            }
        }

        System.out.println(dp[1]);  // 첫날부터 시작할 때 최대 수익
    }
}

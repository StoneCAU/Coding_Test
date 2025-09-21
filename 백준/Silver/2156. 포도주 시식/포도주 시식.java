import java.io.*;
import java.util.*;

public class Main {

    // 포도주 n잔이 일렬로 주어진다
    // 연속으로 3잔을 못마실 때, 가장 많은 양의 포도주를 먹는 방법은?
    public static void main(String[] args) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] cup = new int[n+1];

        for (int i=1;i<=n;++i) {
            cup[i] = Integer.parseInt(br.readLine());
        }
        
        if (n==1) {
            System.out.println(cup[1]);
            return;
        }

        // dp[i]: i번째 잔을 마셨을 때, 최대치
        // 1. dp[i-1]: i번째 잔 마시지 않음
        // 2. i번째 잔만 마심(= i-1은 안 마심) -> dp[i-2] + cup[i]
        // 3. i-1, i 연속 두 잔 마심(= i-2는 안 마심) -> dp[i-3] + cup[i-1] + cup[i]
        int[] dp = new int[n+1];
        dp[1] = cup[1];
        dp[2] = cup[1] + cup[2];

        for (int i=3;i<=n;++i) {
            dp[i] = Math.max(Math.max(dp[i-1], dp[i-2] + cup[i]), dp[i-3] + cup[i-1] + cup[i]);
        }

        System.out.println(dp[n]);
    }
}
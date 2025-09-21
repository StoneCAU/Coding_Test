import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        boolean[] dp = new boolean[n+1]; // 현재 상태에서 돌이 n개일 떄 이길 수 있으면 true

        if (n == 1) {
            System.out.println("SK");
            return;
        }
        
        // 돌이 n개 있다.
        // 돌은 1개 또는 3개를 가져간다
        // 마지막 돌을 가져가는 사람이 승리
        // 완벽하게 게임을 했을 때, 이기는 사람 who?
        dp[0] = false;
        dp[1] = true;
        dp[2] = false;

        for (int i=3;i<=n;++i) {
            dp[i] = !dp[i-1] || !dp[i-3];
        }

        if (dp[n]) {
            System.out.println("SK");
        }
        else System.out.println("CY");
    }
}
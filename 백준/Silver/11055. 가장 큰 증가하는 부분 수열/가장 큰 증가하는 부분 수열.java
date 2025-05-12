import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n+1];
        int[] dp = new int[n+1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i=1;i<=n;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            dp[i] = arr[i];
        }

        for (int i=1;i<=n;i++) {
            for (int j=1;j<i;j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + arr[i]);
                }
            }
        }

        int max = Arrays.stream(dp, 1, n+1).max().getAsInt();

        bw.write(String.valueOf(max));
        bw.flush();
    }
}
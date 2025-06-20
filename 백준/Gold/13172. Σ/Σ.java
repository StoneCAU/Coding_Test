import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 1000000007;

    static long pow(long base, long exp) {
        long res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int m = Integer.parseInt(br.readLine());
        long sum = 0;

        for (int i=0;i<m;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long n = Long.parseLong(st.nextToken());
            long s = Long.parseLong(st.nextToken());

            // 페르마의 소정리 n^(MOD-2)
            sum = (sum + s * pow(n, MOD - 2)) % MOD;
        }

        System.out.println(sum);
    }
}

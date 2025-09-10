import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static int div = 1000000007;

    static long func(int x) {
        if (x == 1) return 2;

        long k = func(x/2);
        if (x % 2 == 0) return k * k % div;
        else return k * k * 2 % div;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());

        for (int i=0;i<t;++i) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            
            if (n == 1 || n == 2) System.out.println(1);
            else System.out.println(func(n-2));
        }

    }
}
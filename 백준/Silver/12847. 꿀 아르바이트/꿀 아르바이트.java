import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        long[] arr = new long[n+1];

        st = new StringTokenizer(br.readLine());
        for (int i=1;i<=n;i++) {
            arr[i] = arr[i-1] + Integer.parseInt(st.nextToken());
        }

        long max = Long.MIN_VALUE;
        for (int i=1;i+m-1<=n;i++) {
            max = Math.max(max, arr[i+m-1]-arr[i-1]);
        }
        bw.write(String.valueOf(max));
        bw.flush();
    }

}
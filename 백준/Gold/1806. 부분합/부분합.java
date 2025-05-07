import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());

        long[] arr = new long[n+1];
        st = new StringTokenizer(br.readLine());
        for (int i=0;i<n;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        long sum = 0;
        int start = 0;
        int end = 0;
        int minLen = Integer.MAX_VALUE;

        while(true) {
            if (sum >= s) {
                minLen = Math.min(minLen, end - start);
                sum -= arr[start++];
            }
            else if (end == n) {
                break;
            }
            else {
                sum += arr[end++];
            }
        }

        if (minLen == Integer.MAX_VALUE) bw.write(String.valueOf(0));
        else bw.write(String.valueOf(minLen));
        bw.flush();
    }
}
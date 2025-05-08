import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());

        int[] arr = new int[n+1];
        st = new StringTokenizer(br.readLine());
        for (int i=1;i<=n;i++) {
            arr[i] = arr[i-1] + Integer.parseInt(st.nextToken());
        }

        int max = 0;
        int cnt = 0;
        for (int i=1;i+x-1<=n;i++) {
            if (max < arr[i+x-1]-arr[i-1]) {
                max = arr[i+x-1]-arr[i-1];
                cnt = 1;
            }
            else if (max == arr[i+x-1] - arr[i-1]) cnt++;
        }

        if (max == 0) {
            bw.write("SAD");
        }
        else {
            bw.write(max + "\n");
            bw.write(String.valueOf(cnt));
        }

        bw.flush();
    }
}
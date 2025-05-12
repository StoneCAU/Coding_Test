import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i=1;i<=n;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] up = new int[n+1];
        int[] down = new int[n+1];
        Arrays.fill(up,1);
        Arrays.fill(down,1);

        for (int i=1;i<=n;i++) {
            for (int j=1;j<i;j++) {
                if (arr[i] > arr[j]) {
                    up[i] = Math.max(up[i], up[j]+1);
                }
            }
        }

        for (int i=n;i>=1;i--) {
            for (int j=n;j>i;j--) {
                if (arr[i] > arr[j]) {
                    down[i] = Math.max(down[i], down[j]+1);
                }
            }
        }

        int[] sum = new int[n+1];
        for (int i=1;i<=n;i++) {
            sum[i] = up[i] + down[i] - 1;
            //System.out.println(up[i] + " " + down[i] + " " + i);
        }

        int max = Arrays.stream(sum,1,n+1).max().getAsInt();

        bw.write(String.valueOf(max));
        bw.flush();
    }
}
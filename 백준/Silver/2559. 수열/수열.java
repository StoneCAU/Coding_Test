import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

       StringTokenizer st = new StringTokenizer(br.readLine());

       int n = Integer.parseInt(st.nextToken());
       int k = Integer.parseInt(st.nextToken());

       int[] arr = new int[n+1];

       st = new StringTokenizer(br.readLine());

       for (int i=1;i<=n;i++) {
           arr[i] = arr[i-1] + Integer.parseInt(st.nextToken());
       }

       int M = Integer.MIN_VALUE;
       
       for (int i=1;i+k-1<=n;i++) {
           M = Math.max(M, arr[i+k-1]-arr[i-1]);
       }

       bw.write(String.valueOf(M));
       bw.flush();
    }
}
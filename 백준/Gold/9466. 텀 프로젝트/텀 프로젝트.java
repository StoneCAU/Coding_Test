import java.io.*;
import java.util.*;

public class Main {

    static int[] arr;
    static int cnt = 0;
    static boolean[] visited;
    static boolean[] finished;

    // 1 -> 3 -> 3
    // 2 -> 1 -> 3 -> 3
    // 3 -> 3
    // 4 -> 7 -> 6 -> 4
    // 5 -> 3 -> 3
    // 6 -> 4 -> 7 -> 6
    // 7 -> 6 -> 4 -> 7

    static void dfs(int cur) {
        visited[cur] = true;

        int next = arr[cur];

        if (!visited[next]) dfs(next);
        // 사이클 발견 & 검사 끝 X
        else if (!finished[next]) {
            for (int temp=next; temp!=cur; temp=arr[temp]) {
                cnt++;
            }
            cnt++;
        }

        finished[cur] = true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());

        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            cnt = 0;

            arr = new int[n + 1];
            visited = new boolean[n + 1];
            finished = new boolean[n + 1];

            st = new StringTokenizer(br.readLine());
            for (int i=1;i<=n;i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            for (int i=1;i<=n;i++) {
                if (!finished[i]) dfs(i);
            }

            System.out.println(n - cnt);
        }

        br.close();
    }
}

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    // W x W 정사각형 범위 내에 친구들의 수 = 자리의 만족도
    // 만족도가 가장 높은 자리를 찾기
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int k = (w-1) / 2;

        int[][] room = new int[r+1][c+1];

        for (int i=0;i<n;++i) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            room[x][y] = 1;
        }

        int[][] prefixSum = new int[r+1][c+1];
        for (int i=1;i<=r;++i) {
            for (int j=1;j<=c;++j) {
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + room[i][j];
            }
        }

        int maxSatisfy = -1;
        int x = -1, y = -1;

        for (int i=1;i<=r;++i) {
            for (int j=1;j<=c;++j) {
                if (room[i][j] == 1) continue;
                
                // (i-k, j-k) ~ (i+k, j+k)
                int sx = Math.max(i - k, 1);
                int sy = Math.max(j - k, 1);
                int ex = Math.min(i + k, r);
                int ey = Math.min(j + k, c);
                int sum = prefixSum[ex][ey] - prefixSum[ex][sy-1] - prefixSum[sx-1][ey] + prefixSum[sx-1][sy-1];

                if (sum > maxSatisfy) {
                    maxSatisfy = sum;
                    x = i; y = j;
                }
            }
        }

        System.out.println(maxSatisfy);
        System.out.println(x + " " + y);
    }
}
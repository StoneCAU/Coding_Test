import java.io.*;
import java.util.*;

public class Main {
    static int n,m,d;
    static int[][] arr;
    static int[][] arrCopy;

    // 1. 가장 가까운 적(가장 마지막 행부터 검사)
    // 2. 가장 왼쪽에 있는 적(index 0부터 검사)
    static int[] findEnemy(int idx) {
        int minDist = 100000000;
        int t = m;
        int[] target = new int[]{-1};

        for (int i=n-1;i>=0;i--) {
            for (int j=0;j<m;j++) {
                int dist = calDistance(i, j, n, idx);
                if (dist > d) continue;

                if (arrCopy[i][j] == 1 && minDist >= dist) {
                    if (minDist == dist && j >= t) continue;

                    minDist = dist;
                    target = new int[]{i, j};
                    t = j;
                }
            }
        }
        return target;
    }

    static int calDistance(int r1, int c1, int r2, int c2) {
        return Math.abs(r1-r2) + Math.abs(c1-c2);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());

        arr = new int[n+1][m+1];

        // 맵 초기화
        for (int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0;j<m;j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 궁수 위치 경우의 수 뽑기
        List<int[]> archers = new ArrayList<>();
        for (int i=0;i<m;i++) {
            for (int j=i+1;j<m;j++) {
                for (int k=j+1;k<m;k++) {
                    int[] idx = new int[]{i, j, k};
                    archers.add(idx);
                }
            }
        }

        // 최댓값 계산
        int maxKills = 0;

        // 모든 경우의 수 돌기
        for (int[] archer : archers) {
            // 해당 경우의 수에서 죽일 수 있는 적의 수
            int totalKills = 0;

            // 맵 copy
            arrCopy = new int[n+1][m+1];
            for (int i=0;i<n;i++) {
                arrCopy[i] = arr[i].clone();
            }

            // 라운드 돌기
            for (int i=0;i<n;i++) {
                // 적 좌표 저장할 HashSet
                HashSet<String> hs = new HashSet<>();

                // 공격할 적 정하기
                for (int idx : archer) {
                    int[] enemy = findEnemy(idx);

                    if (enemy[0] == -1) continue;
                    hs.add(enemy[0] + "," + enemy[1]);
                }

                // 적 제거하기
                for (String enemy : hs) {
                    String[] pos = enemy.split(",");
                    int x = Integer.parseInt(pos[0]);
                    int y = Integer.parseInt(pos[1]);
                    arrCopy[x][y] = 0;
                    totalKills++;
                }

                // 적 이동
                for (int j = n-2;j>=0;j--) {
                    arrCopy[j+1] = arrCopy[j].clone();
                }

                // 맨 첫 줄은 0으로 초기화
                Arrays.fill(arrCopy[0], 0);
            }

            maxKills = Math.max(maxKills, totalKills);
        }

        System.out.println(maxKills);
    }
}

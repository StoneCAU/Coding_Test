import java.io.*;
import java.util.*;

public class Main {
    static int n,m,d;
    static int[][] arr;

    static class Pair implements Comparable<Pair> {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair o) {
            int cmp = Integer.compare(this.x, o.x);
            if (cmp == 0) {
                return Integer.compare(this.y, o.y);
            }
            return cmp;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            Pair pair = (Pair) obj;
            return x == pair.x && y == pair.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }

    static class Atk implements Comparable<Atk> {
        Pair pair;
        int dist;

        Atk(Pair pair, int dist) {
            this.pair = pair;
            this.dist = dist;
        }

        @Override
        public int compareTo(Atk o) {
            int cmp = Integer.compare(this.dist, o.dist);
            if (cmp == 0) {
                cmp = Integer.compare(this.pair.y, o.pair.y);
            }

            return cmp;
        }
    }

    static List<List<Integer>> genCombinations() {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        backtrack(0,3, cur, res);
        return res;
    }

    static void backtrack(int start, int remain, List<Integer> cur, List<List<Integer>> res) {
        // 3명 위치 선정 완료
        if (remain == 0) {
            res.add(new ArrayList<>(cur));
            return;
        }

        // 가지치기
        if (start > m || (m - start + 1) < remain) return;

        for (int i=start;i<=m;i++) {
            cur.add(i);
            backtrack(i+1, remain-1, cur, res);
            cur.remove(cur.size() - 1);
        }
    }

    static int calDistance(int r1, int c1, int r2, int c2) {
        return Math.abs(r1-r2) + Math.abs(c1-c2);
    }

    static int play(List<Integer> comb) {
        // 배열 복사
        int[][] temp = new int[n+1][m+1];
        for (int i=0;i<n;i++) {
            temp[i] = arr[i].clone();
        }

        int kill = 0;

        // n 라운드 진행
        for (int i=1;i<=n;i++) {
            HashSet<Pair> set = new HashSet<>();

            // 궁수 한 명 당 공격할 수 있는 적 선택
            for (int a : comb) {
                int x = n;
                int y = a;

                List<Atk> attacks = new ArrayList<>();

                for (int j=0;j<n;j++) {
                    for (int k=0;k<m;k++) {
                        int dist = calDistance(x,y,j,k);
                        if (temp[j][k] == 1 && dist <= d) {
                            attacks.add(new Atk(new Pair(j,k), dist));
                        }
                    }
                }

                if (attacks.isEmpty()) continue;

                Collections.sort(attacks);

                Atk atk = attacks.get(0);
                set.add(new Pair(atk.pair.x, atk.pair.y));
            }

            for (Pair atk : set) {
                temp[atk.x][atk.y] = 0;
                kill++;
            }

            // 적 이동
            for (int j=n-2;j>=0;j--) {
                temp[j+1] = temp[j].clone();
            }

            for (int j=0;j<m;j++) {
                temp[0][j] = 0;
            }
        }

        return kill;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());

        arr = new int[n+1][m+1];

        // 초기 맵
        for (int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0;j<m;j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // mC3
        List<List<Integer>> res = genCombinations();
        int maxKill = 0;

        for (List<Integer> comb : res) {

            maxKill = Math.max(maxKill, play(comb));
        }

        System.out.println(maxKill);
    }
}

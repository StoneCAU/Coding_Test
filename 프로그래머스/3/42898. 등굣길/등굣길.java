import java.util.*;

class Solution {
    int n, m;
    int[][] visited;
    int[] dx = {0, 1};
    int[] dy = {1, 0};

    public int solution(int m, int n, int[][] puddles) {
        this.m = m;
        this.n = n;
        visited = new int[n + 1][m + 1];

        for (int i = 0; i <= n; i++) {
            Arrays.fill(visited[i], -1);
        }

        for (int[] puddle : puddles) {
            int x = puddle[1]; // y좌표
            int y = puddle[0]; // x좌표
            visited[x][y] = -2;
        }

        return dfs(1, 1);
    }

    private int dfs(int x, int y) {
        if (x == n && y == m) return 1;
        if (visited[x][y] != -1) return Math.max(0, visited[x][y]);

        visited[x][y] = 0;

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (visited[nx][ny] == -2) continue;

            visited[x][y] = (visited[x][y] + dfs(nx, ny)) % 1_000_000_007;
        }

        return visited[x][y];
    }
}

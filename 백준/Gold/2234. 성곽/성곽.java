import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[][] board;
    static int[][] roomId;
    static List<Integer> roomSizes;

    static int rooms = 0;
    static int maxArea = 0;
    static int maxAreaWhenErased = 0;

    // 서, 북, 동, 남 순서
    static int[] dx = {0, -1, 0, 1};
    static int[] dy = {-1, 0, 1, 0};

    static int bfs(int x, int y, int id) {
        int res = 1;

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{x, y});
        roomId[x][y] = id;

        while (!q.isEmpty()) {
            int[] p = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = p[0] + dx[i];
                int ny = p[1] + dy[i];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if ((board[p[0]][p[1]] & (1 << i)) != 0) continue;
                if (roomId[nx][ny] != -1) continue;

                roomId[nx][ny] = id;
                q.add(new int[]{nx, ny});
                res++;
            }
        }

        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        roomId = new int[m][n];
        board = new int[m][n];
        roomSizes = new ArrayList<>();

        // roomId 초기화
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                roomId[i][j] = -1;
            }
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 방의 갯수 & 가장 넓은 방의 넓이
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (roomId[i][j] != -1) continue;

                int area = bfs(i, j, rooms);
                roomSizes.add(area);
                rooms++;
                maxArea = Math.max(maxArea, area);
            }
        }

        // 벽 하나 제거해서 얻을 수 있는 가장 넓은 방의 크기
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 서, 북, 동, 남 순서
                for (int k = 0; k < 4; k++) {
                    // 해당 방향에 벽이 없으면 continue
                    if ((board[i][j] & (1 << k)) == 0) continue;

                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    // 경계 체크
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                    // 서로 다른 방인지 확인
                    int room1 = roomId[i][j];
                    int room2 = roomId[nx][ny];

                    if (room1 != room2) {
                        int combinedSize = roomSizes.get(room1) + roomSizes.get(room2);
                        maxAreaWhenErased = Math.max(maxAreaWhenErased, combinedSize);
                    }
                }
            }
        }


        System.out.println(rooms);
        System.out.println(maxArea);
        System.out.println(maxAreaWhenErased);
    }
}
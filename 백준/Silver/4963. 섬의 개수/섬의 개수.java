import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;

public class Main {
  public static int w;
  public static int h;
  public static int[] dx = {1,-1,0,0,-1,-1,1,1};
  public static int[] dy = {0,0,1,-1,-1,1,-1,1};

  static int[][] board;
  static int[][] visited;

  public static class Pair {
    int x,y;

    Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  public static void bfs(Pair p) {

    Queue<Pair> q = new LinkedList<>();

    visited[p.x][p.y] = 1;

    q.add(p);

    while (!q.isEmpty()) {
      Pair cur = q.poll();

      for (int i = 0; i < 8; i++) {

        int nx = cur.x + dx[i];
        int ny = cur.y + dy[i];

        Pair np = new Pair(nx, ny);

        if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if (visited[nx][ny] == 1) continue;
        if (board[nx][ny] == 0) continue;

        visited[nx][ny] = 1;
        q.add(np);
      }
    }
  }



  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    while(true) {
      int cnt = 0;

      w = sc.nextInt();
      h = sc.nextInt();

      board = new int[h][w];
      visited = new int[h][w];

      Vector<Pair> v = new Vector<>();

      if(w == 0 && h == 0) break;

      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          int n = sc.nextInt();
          board[i][j] = n;

          if(n==1) v.add(new Pair(i,j));
        }
      }

      for(int i = 0; i < v.size(); i++) {
        Pair p = v.get(i);

        int x = p.x;
        int y = p.y;

        if(visited[x][y] == 1) continue;

        bfs(p);
        cnt++;
      }

      System.out.println(cnt);
    }

  }
}
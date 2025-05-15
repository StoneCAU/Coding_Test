import java.io.*;
import java.util.*;

class Solution {
    
    static class Pair {
        int x, y;
        
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    static int ix, iy;
    static int[][] visited = new int[101][101];
    static int[][] map = new int[101][101];
    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,1,-1};
    
    static void bfs(int x, int y) {
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(x, y));
        
        visited[x][y] = 1;
        
        while(!q.isEmpty()) {
            Pair p = q.poll();
            
            if (p.x == ix && p.y == iy) return;
            
            for (int i=0;i<4;i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                
                if (nx < 0 || nx > 100 || ny < 0 || ny > 100) continue;
                if (visited[nx][ny] >= 1) continue;
                if (map[nx][ny] != 1) continue;
                q.offer(new Pair(nx, ny));
                visited[nx][ny] = visited[p.x][p.y] + 1;
            }
        }
    }
    
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        ix = itemX * 2;
        iy = itemY * 2;
        
        for (int[] rect : rectangle) {
            int x1 = rect[0] * 2;
            int y1 = rect[1] * 2;
            int x2 = rect[2] * 2;
            int y2 = rect[3] * 2;
            
            // 1. 내부 -1로 마킹
            for (int i=x1+1;i<x2;i++) {
                for (int j=y1+1;j<y2;j++) {
                    map[i][j] = -1;
                }
            }
            
            // 2. 테두리 1로 마킹
            for (int i=x1;i<=x2;i++) {
                if (map[i][y1] != -1) map[i][y1] = 1;
                if (map[i][y2] != -1) map[i][y2] = 1;
            }
            for (int i=y1;i<=y2;i++) {
                if (map[x1][i] != -1) map[x1][i] = 1;
                if (map[x2][i] != -1) map[x2][i] = 1;
            }
        }
        
        for (int i=0;i<10;i++) {
            for (int j=0;j<10;j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println("");
        }
        
        bfs(characterX * 2, characterY * 2);
        
        int answer = visited[ix][iy];
        return answer / 2;
    }
}
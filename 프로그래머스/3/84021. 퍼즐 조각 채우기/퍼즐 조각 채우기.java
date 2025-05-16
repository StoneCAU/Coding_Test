import java.util.*;

class Point {
    int x,y;
    
    Point(int x, int y) {
        this.x=x;
        this.y=y;
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Point)) return false;
        Point p = (Point) o;
        return x == p.x && y == p.y;
    }
    
    @Override
    public int hashCode() {
        return Objects.hash(x,y);
    }
}

class Solution {
    // 1. 퍼즐 조각 추출
    // 2. 게임 보드 빈 칸 추출
    // 3. 퍼즐 회전시켜가면서 맞는곳 확인(좌표 정규화 시킬 것)
    List<List<Point>> pieces = new ArrayList<>();
    List<List<Point>> blanks = new ArrayList<>();
    
    boolean[][] visited;
    int[] dx = {1,-1,0,0};
    int[] dy = {0,0,1,-1};
    int N;
    
    public int solution(int[][] game_board, int[][] table) {
        N = table.length;
        visited = new boolean[N][N];
        
        // 1. 퍼즐 조각 추출
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (!visited[i][j] && table[i][j] == 1) {
                    pieces.add(getNormalizedShape(table, 1, i, j));
                }
            }
        }
        
        // 방문 배열 초기화
        visited = new boolean[N][N];
        
        // 2. 게임 보드 빈 칸 추출
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (!visited[i][j] && game_board[i][j] == 0) {
                    blanks.add(getNormalizedShape(game_board, 0 ,i, j));
                }
            }
        }
        
        // 3. 퍼즐 회전시켜가면서 맞는곳 확인
        boolean[] used = new boolean[pieces.size()];
        int answer = 0;
            
        for (List<Point> blank : blanks) {
            List<Point> normBlank = normalize(blank);
            
            for (int i=0;i<pieces.size();i++) {
                if (used[i]) continue;
                List<Point> piece = pieces.get(i);
                
                for (int r=0;r<4;r++) {
                    List<Point> normPiece = normalize(piece);
                    
                    if (normBlank.equals(normPiece)) {
                        answer += normBlank.size();
                        used[i] = true;
                        break;
                    }
                    
                    piece = rotate(piece);
                }
                
                if (used[i]) break;
            }
        }
        
        return answer;
    }

    
    private List<Point> getNormalizedShape(int[][] board, int target, int x, int y) {
        Queue<Point> q = new LinkedList<>();
        List<Point> res = new ArrayList<>();
        q.offer(new Point(x,y));
        visited[x][y] = true;
        res.add(new Point(x, y));
        
        while(!q.isEmpty()) {      
            Point p = q.poll();
            
            for (int i=0;i<4;i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (visited[nx][ny] || board[nx][ny] != target) continue;
                
                res.add(new Point(nx, ny));
                visited[nx][ny] = true;
                q.offer(new Point(nx, ny));
            }
        }
        
        return normalize(res);
    }
    
    // 오른쪽 90도 회전
    private List<Point> rotate(List<Point> points) {
        List<Point> res = new ArrayList<>();
        
        for (Point p : points) {
            res.add(new Point(p.y, N-p.x-1));
        }
    
        return res;
    }
    
    private List<Point> normalize(List<Point> points) {
        int minX = Integer.MAX_VALUE;
        int minY = Integer.MAX_VALUE;
        
        for (Point p : points) {
            minX = Math.min(minX, p.x);
            minY = Math.min(minY, p.y);
        }
        
        List<Point> res = new ArrayList<>();
        
        for (Point p : points) {
            res.add(new Point(p.x-minX, p.y-minY));
        }
        
        res.sort(Comparator
                 .comparingInt((Point p) -> p.x)
                 .thenComparingInt(p -> p.y));
        
        return res;
    }
}
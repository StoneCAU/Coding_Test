import java.io.*;
import java.util.*;

public class Main {
    static class Fish implements Comparable<Fish> {
        int id, x, y, dir;

        Fish(int id, int x, int y, int dir) {
            this.id = id;
            this.x = x;
            this.y = y;
            this.dir = dir;
        }

        @Override
        public int compareTo(Fish o) {
            return Integer.compare(this.id, o.id);
        }
    }

    // ↑, ↖, ←, ↙, ↓, ↘, →, ↗
    static int[] dx = {0,-1,-1,0,1,1,1,0,-1};
    static int[] dy = {0,0,-1,-1,-1,0,1,1,1};

    static int maxTot = Integer.MIN_VALUE;

    static void move(Fish[][] arr, List<Fish> fishes, int sx, int sy) {
        if (fishes.isEmpty()) return;
        Collections.sort(fishes);

        for (Fish fish : fishes) {
            for (int i=0;i<=8;i++) {
                int ndir = fish.dir + i;
                if (ndir > 8) ndir -= 8;
                int nx = fish.x + dx[ndir];
                int ny = fish.y + dy[ndir];

                if (nx == sx && ny == sy) continue;
                if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;

                fish.dir = ndir;

                if (arr[nx][ny] == null) {
                    arr[fish.x][fish.y] = null;
                    fish.x = nx;
                    fish.y = ny;
                    arr[nx][ny] = fish;
                }
                else {
                    Fish other = arr[nx][ny];
                    arr[fish.x][fish.y] = other;
                    arr[nx][ny] = fish;

                    int tempX = fish.x, tempY = fish.y;
                    fish.x = nx;
                    fish.y = ny;
                    other.x = tempX;
                    other.y = tempY;
                }

                break;
            }
        }
    }

    static List<Fish> find(Fish[][] arr, int sx, int sy, int sd) {
        List<Fish> canEat = new ArrayList<>();

        for (int i = 1; i <= 3; i++) {
            int nx = sx + dx[sd] * i;
            int ny = sy + dy[sd] * i;

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
                break;
            }

            if (arr[nx][ny] != null) {
                canEat.add(arr[nx][ny]);
            }
        }

        return canEat;
    }
    
    static class GameState {
        Fish[][] board;
        List<Fish> fishes;

        GameState(Fish[][] originalBoard, List<Fish> originalFishes) {
            // 1. 먼저 새로운 Fish 객체들을 담은 리스트 생성
            fishes = new ArrayList<>();
            Map<Integer, Fish> fishMap = new HashMap<>();

            for (Fish original : originalFishes) {
                Fish newFish = new Fish(original.id, original.x, original.y, original.dir);
                fishes.add(newFish);
                fishMap.put(original.id, newFish);
            }

            // 2. 보드 생성하면서 리스트의 Fish 객체들로 채움
            board = new Fish[4][4];
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (originalBoard[i][j] != null) {
                        board[i][j] = fishMap.get(originalBoard[i][j].id);
                    }
                }
            }
        }
    }

    static void dfs(int score, int sx, int sy, int sd, Fish[][] board, List<Fish> curFishes) {
        GameState state = new GameState(board, curFishes);

        // 1. 물고기 이동
        move(state.board, state.fishes, sx, sy);

        // 2. 먹을 수 있는 물고기 찾기
        List<Fish> canEat = find(state.board, sx, sy, sd);

        if (canEat.isEmpty()) {
            maxTot = Math.max(maxTot, score);
            return;
        }

        // 3. 각 물고기를 먹어보기
        for (Fish fishToEat : canEat) {
            GameState nextState = new GameState(state.board, state.fishes);

            // 상어가 물고기를 먹는 처리
            nextState.board[fishToEat.x][fishToEat.y] = null;
            nextState.fishes.removeIf(f -> f.id == fishToEat.id);

            int nextSx = fishToEat.x;
            int nextSy = fishToEat.y;
            int nextSd = fishToEat.dir;

            dfs(score + fishToEat.id, nextSx, nextSy, nextSd, nextState.board, nextState.fishes);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int tot = 0;
        int sx = 0, sy = 0, sd = -1;
        Fish[][] arr = new Fish[4][4];
        List<Fish> fishes = new ArrayList<>();

        for (int i=0;i<4;i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0;j<4;j++) {
                int id = Integer.parseInt(st.nextToken());
                int dir = Integer.parseInt(st.nextToken());

                if (i == 0 && j == 0) {
                    tot += id;
                    sd = dir;
                    continue;
                }

                Fish fish = new Fish(id, i, j, dir);
                arr[i][j] = fish;
                fishes.add(fish);
            }
        }

        dfs(tot, sx, sy, sd, arr, fishes);

        System.out.println(maxTot);
    }
}
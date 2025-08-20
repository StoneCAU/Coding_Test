#include <bits/stdc++.h>

using namespace std;

// 가희는 가만히 있거나 움직일 수 있음(상하좌우)
// T초만큼 이동했을 때 최대한 많이 먹도록 만드어주라
int r, c, t;
char board[101][101];
int visited[101][101][11];

int dx[] = {1,-1,0,0,0};
int dy[] = {0,0,1,-1,0};

int gr, gc;
int max_cnt = 0;

void dfs(int x, int y, int T, int cnt) {
    if (T == t) {
        max_cnt = max(cnt, max_cnt);
        return;
    }

    for (int i=0;i<5;++i) {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (board[nx][ny] == '#') continue;
        if (board[nx][ny] == 'S') {
            board[nx][ny] = '.';
            dfs(nx, ny, T+1, cnt+1);
            board[nx][ny] = 'S';
        }
        else dfs(nx, ny, T+1, cnt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;

    for (int i=0;i<r;++i) {
        for (int j=0;j<c;++j) {
            cin >> board[i][j];
            if (board[i][j] == 'G') {
                gr = i, gc = j;
                board[i][j] = '.';
            }
        }
    }

    dfs(gr, gc, 0, 0);

    cout << max_cnt;
}
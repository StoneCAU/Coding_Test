#include<bits/stdc++.h>

using namespace std;

int n, m;
int init_rx, init_ry, init_bx, init_by;
char board[11][11];
bool visited[11][11][11][11];

// L, R, U, D 순서
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char dd[] = {'L', 'R', 'U', 'D'};

void initBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (board[i][j] == 'R') {
                board[i][j] = '.';
                init_rx = i;
                init_ry = j;
            }

            if (board[i][j] == 'B') {
                board[i][j] = '.';
                init_bx = i;
                init_by = j;
            }
        }
    }
}

bool checkRange(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (board[x][y] == '#') return false;
    return true;
}

pair<int,int> move(int x, int y, int dir) {
    int nx = x, ny = y;
    while (1) {
        if (!checkRange(nx, ny)) {
            nx -= dx[dir];
            ny -= dy[dir];
            break;
        }

        nx += dx[dir];
        ny += dy[dir];

        if (board[nx][ny] == 'O') break;
    }

    return {nx, ny};
}

tuple<int,int,int,int,string> getNextState(int rx, int ry, int bx, int by, string path, int dir) {
    int nrx = rx, nry = ry, nbx = bx, nby = by;
    string npath = path + dd[dir];
    bool redFirst = false;
    // redFirst인지 정하기 (dir에 따라 다름)
    if (dir == 0) {
        redFirst = rx == bx && ry < by;
    }
    else if (dir == 1) {
        redFirst = rx == bx && ry > by;
    }
    else if (dir == 2) {
        redFirst = rx < bx && ry == by;
    }
    else {
        redFirst = rx > bx && ry == by;
    }

    // 빨간색부터 이동
    if (redFirst) {
        tie(nrx, nry) = move(nrx, nry, dir);
        tie(nbx, nby) = move(nbx, nby, dir);
        if (nrx == nbx && nry == nby && board[nrx][nry] != 'O') {
            nbx -= dx[dir];
            nby -= dy[dir];
        }
    }
    else {
        tie(nbx, nby) = move(nbx, nby, dir);
        tie(nrx, nry) = move(nrx, nry, dir);
        if (nrx == nbx && nry == nby && board[nrx][nry] != 'O') {
            nrx -= dx[dir];
            nry -= dy[dir];
        }
    }

    return {nrx, nry, nbx, nby, npath};
}

void printBoard(int rx, int ry, int bx, int by) {
    cout << "\n";
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (rx == i && ry == j) {
                cout << "R";
                continue;
            }
            if (bx == i && by == j) {
                cout << "B";
                continue;
            }
            cout << board[i][j];
        }
        cout << "\n";
    }
}

string bfs() {
    queue<tuple<int,int,int,int,string>> q;
    q.push({init_rx, init_ry, init_bx, init_by, ""});
    visited[init_rx][init_ry][init_bx][init_by] = true;

    while (!q.empty()) {
        auto [rx, ry, bx, by, path] = q.front();
        q.pop();

        if (path.length() >= 10) continue;

        for (int dir=0;dir<4;dir++) {
            auto [nrx, nry, nbx, nby, npath] = getNextState(rx, ry, bx, by, path, dir);
            
            // 이미 방문한 상태이면 continue
            if (visited[nrx][nry][nbx][nby]) continue;
            // 파란색이 구멍에 빠지면 continue
            if (board[nbx][nby] == 'O') continue;
            // 빨간색만 구멍에 빠졌으면 return
            if (board[nrx][nry] == 'O') return npath;
            visited[nrx][nry][nbx][nby] = true;
            q.push({nrx, nry, nbx, nby, npath});;
        }
    }

    return "";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    initBoard();

    string res = bfs();

    if (res.length() == 0) {
        cout << -1;
        return 0;
    }

    cout << res.size() << "\n";
    cout << res << "\n";
}
#include <bits/stdc++.h>

using namespace std;

int n, m;
char arr[11][11];
int visited[11][11][11][11];

int rx, ry, bx, by;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

queue<tuple<int, int, int, int>> q;

bool range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs() {
    q.push({rx, ry, bx, by});
    visited[rx][ry][bx][by] = 1;

    while (!q.empty()) {
        auto [rxx, ryy, bxx, byy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int rnx = rxx, rny = ryy;
            int bnx = bxx, bny = byy;

            while (range(rnx + dx[i], rny + dy[i]) && arr[rnx + dx[i]][rny + dy[i]] != '#') {
                rnx += dx[i];
                rny += dy[i];
                if (arr[rnx][rny] == 'O') break;
            }

            // 블루가 먼저 도착할 경우
            bool flag = false;

            while (range(bnx + dx[i], bny + dy[i]) && arr[bnx + dx[i]][bny + dy[i]] != '#') {
                bnx += dx[i];
                bny += dy[i];
                if (arr[bnx][bny] == 'O') {
                    flag = true;
                    break;
                }; // 파란 공이 구멍에 빠지면 실패
            }

            if (flag) continue;

            if (arr[rnx][rny] == 'O') return visited[rxx][ryy][bxx][byy]; // 빨간 공만 빠지면 성공

            if (rnx == bnx && rny == bny) {
                if (abs(rnx - rxx) + abs(rny - ryy) > abs(bnx - bxx) + abs(bny - byy)) {
                    rnx -= dx[i];
                    rny -= dy[i];
                } else {
                    bnx -= dx[i];
                    bny -= dy[i];
                }
            }

            if (visited[rnx][rny][bnx][bny]) continue;

            visited[rnx][rny][bnx][bny] = visited[rxx][ryy][bxx][byy] + 1;
            q.push({rnx, rny, bnx, bny});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            arr[i][j] = str[j];
            if (str[j] == 'R') rx = i, ry = j;
            if (str[j] == 'B') bx = i, by = j;
        }
    }

    int cnt = bfs();

    if (cnt > 10) cout << -1;
    else cout << cnt;
}

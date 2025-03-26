#include <bits/stdc++.h>

using namespace std;

int n, m;
int mp[101][101];
int sx, sy, sd; // 출발점
int ex, ey, ed; // 끝점
int visited[101][101][4];

// 동(1), 서(2), 남(3), 북(4)
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};

// trn[동,서,남,북][오른쪽 회전, 왼쪽 회전]
int trn[5][2] = {{0, 0},{3, 4}, {4, 3}, {2, 1}, {1, 2}};


void bfs() {
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, sd});

    while (!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();

        // 오른쪽 회전, 왼쪽 회전
        if (visited[x][y][trn[d][0]] == -1) {
            visited[x][y][trn[d][0]] = visited[x][y][d] + 1;
            q.push({x, y, trn[d][0]});
        }

        if (visited[x][y][trn[d][1]] == -1) {
            visited[x][y][trn[d][1]] = visited[x][y][d] + 1;
            q.push({x, y, trn[d][1]});
        }

        // 직진
        for (int k=1;k<=3;k++) {
            int nx = x + dx[d] * k;
            int ny = y + dy[d] * k;

            if (mp[nx][ny] == 1) break;

            if (nx >= 1 && nx <= m && ny >= 1 && ny <= n) {
                if (visited[nx][ny][d] == -1) {
                    visited[nx][ny][d] = visited[x][y][d] + 1;
                    q.push({nx, ny, d});
                }
            }
        }
    }
}

int main() {
    // 행, 열 입력
    cin >> m >> n;

    // 맵 입력
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mp[i][j];
        }
    }

    // 출발점 입력
    cin >> sx >> sy >> sd;

    // 끝점 입력
    cin >> ex >> ey >> ed;

    // visited 초기화
    memset(visited, -1, sizeof(visited));

    // 시작점 초기화
    visited[sx][sy][sd] = 0;

    bfs();

    cout << visited[ex][ey][ed];
}
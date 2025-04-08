#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int arr[101][101];
int hour = 10001;
int visited[101][101];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// 1. 그람 없이
void bfs() {
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        if (xx == n - 1 && yy == m - 1) {
            hour = min(hour, visited[n - 1][m - 1] - 1);
        }

        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (arr[nx][ny] == 1) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = visited[xx][yy] + 1;
            q.push({nx, ny});
        }
    }
}

// 2. 그람 있이
void gram() {
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = 1;

    int lastX = -1;
    int lastY = -1;

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        if (arr[xx][yy] == 2) {
            lastX = xx;
            lastY = yy;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (arr[nx][ny] == 1) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = visited[xx][yy] + 1;
            q.push({nx, ny});
        }
    }

    if (lastX == -1 || lastY == -1) return;

    int res = visited[lastX][lastY] + (n - 1 - lastX) + (m - 1 - lastY) - 1;
    hour = min(hour, res);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    bfs();

    memset(visited, 0, sizeof(visited));
    gram();

    if (hour > t) cout << "Fail";
    else cout << hour;
}

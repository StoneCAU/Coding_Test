#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n, l, r;
int arr[52][52];
int open[52][52];
int visited[52][52];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int days = 0;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> u;
    int cnt = 1;
    int sum = arr[x][y];
    q.push({ x, y });
    u.push_back({ x, y });
    visited[x][y] = 1;

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (!open[nx][ny] || visited[nx][ny]) continue;

            int cal = abs(arr[xx][yy] - arr[nx][ny]);
            if (cal >= l && cal <= r) {
                visited[nx][ny] = 1;
                sum += arr[nx][ny];
                cnt++;
                q.push({ nx, ny });
                u.push_back({ nx, ny });
            }
        }
    }

    int res = sum / cnt;

    for (auto& p : u) {
        arr[p.first][p.second] = res;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    while (1) {
        bool moved = false;

        for (int i = 0; i < n; i++) {
            fill(open[i], open[i] + n, 0);
            fill(visited[i], visited[i] + n, 0);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                    int cal = abs(arr[i][j] - arr[nx][ny]);
                    if (cal >= l && cal <= r) {
                        open[i][j] = 1;
                        open[nx][ny] = 1;
                        moved = true;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (open[i][j] && !visited[i][j]) {
                    bfs(i, j);
                }
            }
        }

        if (!moved) break; 
        days++; 
    }

    cout << days;

}
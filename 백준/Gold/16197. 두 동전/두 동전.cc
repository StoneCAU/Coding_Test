#include <bits/stdc++.h>
using namespace std;

int n, m;
char arr[21][21];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int fx, fy, sx, sy;
int ans = 11;

void dfs(char temp[21][21], int x1, int y1, int x2, int y2, int cnt) {
    if (cnt >= ans || cnt > 10) return;

    for (int i = 0; i < 4; i++) {
        int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
        int nx2 = x2 + dx[i], ny2 = y2 + dy[i];

        bool out1 = nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= m;
        bool out2 = nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= m;

        // 둘 다 떨어진 경우는 실패
        if (out1 && out2) continue;

        // 하나만 떨어진 경우 성공
        if (out1 || out2) {
            ans = min(ans, cnt);
            return;
        }

        // 임시 맵 복사
        char next[21][21];
        memcpy(next, temp, sizeof(next));

        // 이동 불가능한 경우(벽이면 위치 그대로)
        if (next[nx1][ny1] == '#') {
            nx1 = x1;
            ny1 = y1;
        }
        if (next[nx2][ny2] == '#') {
            nx2 = x2;
            ny2 = y2;
        }

        // 동전 위치 갱신
        next[x1][y1] = '.';
        next[x2][y2] = '.';
        next[nx1][ny1] = 'o';
        next[nx2][ny2] = 'o';

        dfs(next, nx1, ny1, nx2, ny2, cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j];
            if (arr[i][j] == 'o') {
                if (cnt == 0) {
                    fx = i; fy = j;
                    cnt++;
                } else {
                    sx = i; sy = j;
                }
            }
        }
    }

    char temp[21][21];
    memcpy(temp, arr, sizeof(arr));
    dfs(temp, fx, fy, sx, sy, 1);

    if (ans > 10) cout << -1;
    else cout << ans;
}

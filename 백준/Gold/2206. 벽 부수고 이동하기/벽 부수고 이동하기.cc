#include<bits/stdc++.h>

using namespace std;

int n,m;
int board[1001][1001];
bool visited[1001][1001][2]; // 0: 벽 안부숨, 1: 벽 부숨

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int bfs() {
    queue<tuple<int,int,int,int>> q;
    q.push({0,0,0,1});
    visited[0][0][0] = true;

    while (!q.empty()) {
        auto [xx, yy, st, cnt] = q.front();
        q.pop();

        if (xx == n-1 && yy == m-1) return cnt;

        for (int i=0;i<4;i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == 0) {
                if (visited[nx][ny][st]) continue;
                visited[nx][ny][st] = true;
                q.push({nx, ny, st, cnt+1});
            }
            else if (board[nx][ny] == 1) {
                if (visited[nx][ny][1]) continue;
                if (st) continue;
                visited[nx][ny][1] = true;
                q.push({nx, ny, 1, cnt+1});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0;i<n;i++) {
        string str;
        cin >> str;
        for (int j=0;j<m;j++) {
            board[i][j] = str[j] - '0';
        }
    }

    cout << bfs();
}
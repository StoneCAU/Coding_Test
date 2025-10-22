#include <bits/stdc++.h>

using namespace std;

int r, c;
char board[1501][1501];
bool temp[1501][1501];
bool visited[1501][1501];

queue<pair<int,int>> water;
queue<pair<int,int>> swan, swan_next;
int fx = -1, fy = -1, sx = -1, sy = -1; // 백조 위치
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void melt() {
    int sz = (int) water.size();

    for (int k=0;k<sz;++k) {
        int x = water.front().first, y = water.front().second;
        water.pop();

        for (int i=0;i<4;++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

            if (board[nx][ny] == 'X') {
                board[nx][ny] = '.';
                water.emplace(nx, ny);
            }
        }
    }
}

bool bfs() {
    while (!swan.empty()) {
        int xx = swan.front().first;
        int yy = swan.front().second;
        swan.pop();

        if (xx == sx && yy == sy) {
            return true;
        }

        for (int i=0;i<4;++i) {
            int nx = xx + dx[i], ny = yy + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;

            if (board[nx][ny] == 'X') {
                swan_next.emplace(nx, ny);
            }
            else {
                swan.emplace(nx, ny);
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    bool first = true;
    for (int i=0;i<r;++i) {
        for (int j=0;j<c;++j) {
            cin >> board[i][j];

            if (board[i][j] == 'L' || board[i][j] == '.') {
                if (board[i][j] == 'L') {
                    if (first) {
                        fx = i, fy = j;
                        first = false;
                    }
                    else {
                        sx = i, sy = j;
                    }
                }

                water.emplace(i, j);
            }
        }
    }

    swan.emplace(fx, fy);
    visited[fx][fy] = true;

    int ans = 0;
    while (1) {
        if (bfs()) {
            cout << ans;
            break;
        }

        ans++;
        melt();
        swap(swan,swan_next);
    }

}
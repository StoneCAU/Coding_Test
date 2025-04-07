#include <bits/stdc++.h>
using namespace std;

int n, k;
int board[13][13];
deque<int> horse[13][13];
vector<tuple<int, int, int>> pos;

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];

    pos.push_back({0, 0, 0});

    for (int i = 1; i <= k; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        pos.push_back({x, y, d});
        horse[x][y].push_back(i);
    }

    int turn = 0;

    while (1) {
        turn++;

        if (turn > 1000) {
            cout << -1;
            return 0;
        }

        for (int i = 1; i <= k; i++) {
            auto& [x, y, d] = pos[i];
            int nx = x + dx[d];
            int ny = y + dy[d];

            // 현재 위치에서 i번 말 위에 쌓인 말들만 이동
            auto& cell = horse[x][y];
            auto it = find(cell.begin(), cell.end(), i);
            deque<int> moving(it, cell.end());
            cell.erase(it, cell.end());

            // 파란색 or 범위 밖이면 방향 바꾸기
            if (nx < 1 || ny < 1 || nx > n || ny > n || board[nx][ny] == 2) {
                if (d == 1) d = 2;
                else if (d == 2) d = 1;
                else if (d == 3) d = 4;
                else d = 3;
                get<2>(pos[i]) = d;

                nx = x + dx[d];
                ny = y + dy[d];

                // 다시 이동하려 해도 범위 밖이거나 파란색이면 그대로 제자리
                if (nx < 1 || ny < 1 || nx > n || ny > n || board[nx][ny] == 2) {
                    for (int m : moving) horse[x][y].push_back(m); // 다시 원위치
                    continue;
                }
            }

            // 빨간 칸이면 역순
            if (board[nx][ny] == 1)
                reverse(moving.begin(), moving.end());

            for (int m : moving) {
                horse[nx][ny].push_back(m);
                auto& [xx, yy, dd] = pos[m];
                xx = nx;
                yy = ny;
            }

            if (horse[nx][ny].size() >= 4) {
                cout << turn;
                return 0;
            }
        }
    }
}
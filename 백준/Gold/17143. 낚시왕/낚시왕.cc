#include <bits/stdc++.h>

using namespace std;

int R,C,M;
int ans = 0;
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> shark[101][101];

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

// pos: 낚시왕이 위치한 열
void fishing(int pos) {
    // 해당 열 검사
    for (int i=1;i<=R;i++) {
        // 가장 가까이 있는 것 잡기
        if (shark[i][pos].size() > 0) {
            auto [z, s, d] = shark[i][pos].top();
            ans += z;

            shark[i][pos].pop();
            return;
        }
    }
}

// d: 1(위), 2(아래), 3(오른쪽), 4(왼쪽)
// z(크기), s(속력), d(방향)
void move() {
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> temp[101][101];
    // 이동
    for (int i=1;i<=R;i++) {
        for (int j=1;j<=C;j++) {
            if (shark[i][j].empty()) continue;

            while (!shark[i][j].empty()) {
                auto [z, s, d] = shark[i][j].top();
                shark[i][j].pop();

                int x = i, y = j;
                int nd = d;

                if (d == 1 || d == 2) s %= (2 * (R - 1));
                else s %= (2 * (C - 1));

                for (int m = 0; m < s; m++) {
                    int nx = x + dx[nd];
                    int ny = y + dy[nd];

                    if (nx < 1 || nx > R || ny < 1 || ny > C) {
                        if (nd == 1) nd = 2;
                        else if (nd == 2) nd = 1;
                        else if (nd == 3) nd = 4;
                        else if (nd == 4) nd = 3;

                        nx = x + dx[nd];
                        ny = y + dy[nd];
                    }

                    x = nx;
                    y = ny;
                }

                temp[x][y].push({z, s, nd});
            }
        }
    }

    // 잡아먹기
    for (int i=1;i<=R;i++) {
        for (int j=1;j<=C;j++) {
            if (temp[i][j].empty()) continue;

            // 해당 칸에 상어가 1일 때까지 크기가 작은 상어들 pop
            while (temp[i][j].size() != 1) {
                temp[i][j].pop();
            }

            shark[i][j] = temp[i][j];
        }
    }
}

// 1 -> 4
// 1 -> 4 -> 2
// 4 -> 1 -> 6

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> M;

    // M만큼 상어 입력
    for (int i=0;i<M;i++) {
            int r,c,s,d,z;
            cin >> r >> c >> s >> d >> z;

            // (크기, 속력, 이동방향)
            shark[r][c].push({z,s,d});
    }

    // 열만큼 반복
    for (int i=1;i<=C;i++) {
        // 1. 낚시왕이 오른쪽으로 한 칸 이동한다.(i++)
        // 2. 낚시왕이 위치한 열(i)에서 가장 가까운 상어를 잡는다.
        fishing(i);
        // 3. 상어가 이동한다.
        move();
    }

    cout << ans;
}

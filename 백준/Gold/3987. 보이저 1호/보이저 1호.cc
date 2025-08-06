#include <bits/stdc++.h>
using namespace std;

char board[501][501];
bool visited[501][501][4];  // 방향 포함 방문 체크
int n, m;
int cx, cy;
int max_time = -1;
char max_dir;

// 위, 오, 아래, 왼
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// '/' 거울 반사
int reflect_slash[4] = {1, 0, 3, 2};
// '\' 거울 반사
int reflect_back[4]  = {3, 2, 1, 0};

int simulate(int dir) {
    memset(visited, 0, sizeof(visited));
    int x = cx, y = cy;
    int time = 0;

    while (true) {
        x += dx[dir];
        y += dy[dir];
        time++;

        // 밖으로 나가면 종료
        if (x <= 0 || x > n || y <= 0 || y > m) break;

        // 블랙홀 만나면 종료
        if (board[x][y] == 'C') break;

        // 무한루프 탐지
        if (visited[x][y][dir]) return -1;  // Voyager
        visited[x][y][dir] = true;

        // 거울 반사
        if (board[x][y] == '/') dir = reflect_slash[dir];
        else if (board[x][y] == '\\') dir = reflect_back[dir];
    }

    return time;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];
    cin >> cx >> cy;

    const char dir_char[4] = {'U', 'R', 'D', 'L'};

    for (int d = 0; d < 4; d++) {
        int t = simulate(d);
        if (t == -1) {
            cout << dir_char[d] << "\nVoyager\n";
            return 0;
        }
        if (t > max_time) {
            max_time = t;
            max_dir = dir_char[d];
        }
    }

    cout << max_dir << '\n' << max_time << '\n';
}

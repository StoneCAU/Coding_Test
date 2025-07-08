#include<bits/stdc++.h>

using namespace std;

int r, c, n;
int board[201][201]; // 남은 시간이 들어감. 파괴상태(아무것도없음): -1
int sec = 1;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void bomb(int x, int y) {
    // 현재 위치 폭탄 파괴
    board[x][y] = -1;

    // 인접한 폭탄 파괴
    for (int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (board[nx][ny] > 0) board[nx][ny] = -1;
    }
}

void setting() {
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            if (board[i][j] == -1) {
                board[i][j] = 3;
            }
            else board[i][j]--;
        }
    }

    sec++;
}

// 1초가 흐른다
void explode() {
    // 폭발해야할 위치들
    vector<pair<int,int>> bombs;

    // board 시간 감소
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            board[i][j]--;

            // 0초인 곳은 폭발
            if (board[i][j] == 0) {
                bombs.push_back({i, j});
            }
        }
    }

    // 폭발 진행
    for (int i=0;i<bombs.size();i++) {
        bomb(bombs[i].first, bombs[i].second);
    }

    sec++;
}

void printBoard() {
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            if (board[i][j] != -1) cout << "O";
            else cout << ".";
        }
        cout << "\n";
    }
}

// 폭탄이 있는 칸은 3초 뒤 폭발
// 인접한 4칸에 있는 폭탄은 파괴(폭발 X)
// 폭탄 설치 후 가만히(1초) -> 폭탄 없는 곳에 전부 폭탄 설치(2초) -> 처음에 설치한 폭탄 폭파(3초)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> n;

    // 맵 초기화 (1초일 때 상황)
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char state;
            cin >> state;

            if (state == 'O') board[i][j] = 2;
            else board[i][j] = -1;
        }
    }

    // n초동안 반복
    while (n != sec) {
        // 설치 X인 칸 폭탄 설치
        setting();

        if (n == sec) break;

        // 1초 진행
        explode();
    }

    printBoard();
}

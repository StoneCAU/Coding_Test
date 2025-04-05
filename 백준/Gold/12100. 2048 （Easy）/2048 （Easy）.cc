#include <bits/stdc++.h>

using namespace std;

int n;
int board[22][22];
int num = 0;

void printBoard(int board[22][22]) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "---------\n";
}

bool isSame(int a[22][22], int b[22][22]) {
    for (int i =0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

// 90도 시계방향 회전
// 위 -> 3번, 아래 -> 1번, 왼쪽 -> 0번, 오른쪽 -> 2번
// 복원: 위 -> 1번, 아래 -> 3번 ... (4 - dir번)
void rotate(int board[22][22]) {
    int tmp[22][22];

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            tmp[j][n-1-i] = board[i][j];
        }
    }

    memcpy(board, tmp, sizeof(tmp));
}

// dir = 0(왼쪽), 1(아래), 2(오른쪽), 3(위)
void move(int origin[22][22], int dir) {
    int temp[22][22];
    memcpy(temp, origin, sizeof(temp));  // 원본 복사

    int merged[22][22] = {0};

    // 회전
    for (int i = 0; i < dir; i++) {
        rotate(temp);
        rotate(merged);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (temp[i][j] == 0) continue;

            int x = j;

            while (x > 0) {
                if (temp[i][x-1] == 0) {
                    temp[i][x-1] = temp[i][x];
                    temp[i][x] = 0;
                    x--;
                }
                else if (temp[i][x-1] == temp[i][x] && !merged[i][x-1]) {
                    temp[i][x-1] *= 2;
                    temp[i][x] = 0;
                    merged[i][x-1] = 1;
                    break;
                }
                else break;
            }
        }
    }

    // 회전 복원
    for (int i = 0; i < (4 - dir) % 4; i++) {
        rotate(temp);
        rotate(merged);
    }

    memcpy(origin, temp, sizeof(temp));  // 결과를 다시 origin에 복사
}


void dfs(int temp[22][22], int depth) {
    //printBoard(temp);
    // 최댓값 갱신 후 return
    if (depth == 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                num = max(num, temp[i][j]);
            }
        }
        return;
    }

    // 네 방향 이동
    for (int dir = 0; dir < 4; dir++) {
        int newBoard[22][22];
        memcpy(newBoard, temp, sizeof(newBoard));
        move(newBoard, dir);

        if (isSame(newBoard, temp)) continue;

        dfs(newBoard, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    if (n == 1) {
        cout << board[0][0];
        return 0;
    }

    dfs(board, 0);

    cout << num;
}

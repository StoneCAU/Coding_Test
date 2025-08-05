#include<bits/stdc++.h>

using namespace std;

int board[7][8];
int h[8]; // 해당 부분까지 담겨있다는 의미

// x: 열, y: 상근(1), 정인(2)
void down(int x, int y) {
    int t = h[x];
    if (t == -1) {
        h[x] = 6;
        board[6][x] = y;
        return;
    }

    h[x] = t - 1;
    board[t - 1][x] = y;
}

// x: 상근(1), 정인(2)
bool check(int x) {
    // 가로 검사
    for (int i=1;i<=6;i++) {
        for (int j=1;j<=4;j++) {
            bool chk = true;
            //cout << j << "\n";
            for (int k=j;k<=j+3;k++) {
                //cout << i << " " << k << " " << board[i][k] << "\n";
                if (board[i][k] != x) {
                    chk = false;
                    break;
                }
            }
            if (chk) {
                //cout << "test1\n";
                return true;
            }
        }
    }

    // 세로 검사
    for (int j=1;j<=7;j++) {
        for (int k=1;k<=3;k++) {
            bool chk = true;
            for (int i=k;i<=k+3;i++) {
                if (board[i][j] != x) {
                    chk = false;
                    break;
                }
            }
            if (chk) {
                //cout << "test2\n";
                return true;
            }
        }
    }

    // 대각선 검사1
    for (int i=3;i>=1;i--) {
        int cnt = 0;
        int a = i, b = 0;

        if (board[a][b] == x) cnt++;

        while (1) {
            a++, b++;
            if (a > 6 || b > 7) break;
            if (board[a][b] == x) cnt++;
            else cnt = 0;
            if (cnt == 4) return true;
        }
    }

    // 대각선 검사2
    for (int j=4;j>=1;j--) {
        int cnt = 0;
        int a = 0, b = j;

        if (board[a][b] == x) cnt++;
        while (1) {
            a++, b++;
            if (a > 6 || b > 7) break;
            if (board[a][b] == x) cnt++;
            else cnt = 0;
            if (cnt == 4) return true;
        }
    }

    // 대각선 검사3
    for (int j=4;j<=7;j++) {
        int cnt = 0;
        int a = 0, b = j;

        if (board[a][b] == x) cnt++;
        while (1) {
            a++, b--;
            if (a > 6 || b <= 0) break;
            if (board[a][b] == x) cnt++;
            else cnt = 0;
            if (cnt == 4) return true;
        }
    }

    // 대각선 검사4
    for (int i=3;i>=1;i--) {
        int cnt = 0;
        int a = i, b = 7;

        if (board[a][b] == x) cnt++;
        while (1) {
            a++, b--;
            if (a > 6 || b <= 0) break;
            if (board[a][b] == x) cnt++;
            else cnt = 0;
            if (cnt == 4) return true;
        }
    }

    return false;
}

void print() {
    cout << "\n";
    for (int i=1;i<=6;i++) {
        for (int j=1;j<=7;j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// 상근 -> 정인
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(h, h+8, -1);

    // 상근(1), 정인(2)
    for (int i=1;i<=21;i++) {
        int s, j;
        cin >> s >> j;

        down(s,1);

        //print();
        if (check(1)) {
            cout << "sk " << i;
            return 0;
        }

        down(j,2);
        //print();
        if (check(2)) {
            cout << "ji " << i;
            return 0;
        }
    }

    cout << "ss";
}
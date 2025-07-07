#include<bits/stdc++.h>

using namespace std;

int m, n;
int growth[1401];
int board[701][701];

void printBoard() {
    for (int i=0;i<m;i++) {
        for (int j = 0;j<m;j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    vector<int> growth_values(2*m+1, 1);

    for (int i=0;i<n;i++) {
        // 1. 자라는 정도 스스로 결정 (사이드)
        // 입력 받기
        int zero_count, one_count, two_count;
        cin >> zero_count >> one_count >> two_count;

        // 성장값 누적 배열 생성
        int idx = zero_count;

        // 1만큼 성장
        for (int j=0;j<one_count;j++) {
            growth_values[idx++] += 1;
        }

        // 2만큼 성장
        for (int j=0;j<two_count;j++) {
            growth_values[idx++] += 2;
        }
    }

    // 테두리 입력
    int idx = 0;
    for (int i=m-1;i>=0;i--) {
        board[i][0] = growth_values[idx++];
    }

    for (int i=1;i<=m-1;i++) {
        board[0][i] = growth_values[idx++];
    }

    // 나머지 입력
    for (int i=1;i<m;i++) {
        for (int j=1;j<m;j++) {
            board[i][j] = max(max(board[i][j-1], board[i-1][j-1]), board[i-1][j]);
        }
    }

    printBoard();
}

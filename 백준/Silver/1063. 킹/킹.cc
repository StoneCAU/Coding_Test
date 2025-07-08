#include<bits/stdc++.h>

using namespace std;

pair<int,int> king;
pair<int,int> stone;
int n;

pair<int,int> convertToDigit(string str) {
    int col = str[0] - 'A' + 1;  // A=1, B=2, ..., H=8
    int row = str[1] - '0';      // 1=1, 2=2, ..., 8=8
    return {row, col};
}

string convertToStr(pair<int,int> p) {
    return string(1, (char)(p.second - 1 + 'A')) + to_string(p.first);
}

bool isValid(int row, int col) {
    return row >= 1 && row <= 8 && col >= 1 && col <= 8;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string k, s;
    cin >> k >> s >> n;

    king = convertToDigit(k);
    stone = convertToDigit(s);

    for (int i = 0; i < n; i++) {
        string order;
        cin >> order;

        int dx = 0, dy = 0;

        if (order == "R") {
            dy = 1;
        }
        else if (order == "L") {
            dy = -1;
        }
        else if (order == "B") {
            dx = -1;
        }
        else if (order == "T") {
            dx = 1;
        }
        else if (order == "RT") {
            dx = 1;
            dy = 1;
        }
        else if (order == "LT") {
            dx = 1;
            dy = -1;
        }
        else if (order == "RB") {
            dx = -1;
            dy = 1;
        }
        else if (order == "LB") {
            dx = -1;
            dy = -1;
        }

        int new_king_row = king.first + dx;
        int new_king_col = king.second + dy;

        // 킹이 체스판 밖으로 나가면 이동 무시
        if (!isValid(new_king_row, new_king_col)) continue;

        // 킹이 돌과 같은 위치로 이동하려는 경우
        if (new_king_row == stone.first && new_king_col == stone.second) {
            int new_stone_row = stone.first + dx;
            int new_stone_col = stone.second + dy;

            // 돌이 체스판 밖으로 나가면 이동 무시
            if (!isValid(new_stone_row, new_stone_col)) continue;

            // 돌도 같은 방향으로 이동
            stone.first = new_stone_row;
            stone.second = new_stone_col;
        }

        // 킹 이동
        king.first = new_king_row;
        king.second = new_king_col;
    }

    cout << convertToStr(king) << "\n";
    cout << convertToStr(stone) << "\n";
}
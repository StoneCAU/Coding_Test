#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int grd[11][11];
int A[11][11]; // 겨울에 추가되는 양분
deque<int> tr[11][11]; // 나무의 나이 저장
vector<tuple<int, int, int>> die; // 죽은 나무

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int countTree() {
    int cnt = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            cnt += tr[x][y].size();
        }
    }
    return cnt;
}

// 봄
void spring() {
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            if (tr[x][y].empty()) continue;

            deque<int> newTr;
            int eng = grd[x][y];

            for (int i = 0; i < tr[x][y].size(); i++) {
                int age = tr[x][y][i];

                if (eng >= age) {
                    eng -= age;
                    newTr.push_back(age + 1);
                } else {
                    die.push_back({x, y, age});
                }
            }

            tr[x][y] = newTr;
            grd[x][y] = eng;
        }
    }
}

// 여름
void summer() {
    for (auto [x, y, age] : die) {
        grd[x][y] += age / 2;
    }
    die.clear();
}

// 가을
void autumn() {
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            for (int i = 0; i < tr[x][y].size(); i++) {
                int age = tr[x][y][i];

                if (age % 5 != 0) continue;

                for (int d = 0; d < 8; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                    tr[nx][ny].push_front(1); // 어린 나무는 앞에 추가
                }
            }
        }
    }
}

// 겨울
void winter() {
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            grd[x][y] += A[x][y];
        }
    }
}

void cycle() {
    spring();
    summer();
    autumn();
    winter();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            grd[i][j] = 5;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tr[x][y].push_back(z);
    }

    // 나무 나이를 정렬 (작은 나이부터 앞에 오게)
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            sort(tr[x][y].begin(), tr[x][y].end());
        }
    }

    for (int i = 0; i < k; i++) {
        cycle();
    }

    cout << countTree();
}

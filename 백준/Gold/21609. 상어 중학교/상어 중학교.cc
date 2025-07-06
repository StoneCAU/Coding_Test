#include<bits/stdc++.h>

using namespace std;

int n, m;
int score = 0;
int board[21][21];
int visited[21][21];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// 블록 그룹은 일반 블록 색이 모두 같아야함
// 검은색 블록(-1)은 없어야됨
// 무지개 블록(0)은 포함되도됨
// 블록 그룹은 2개 이상의 블록으로 이루어짐
// 블록 그룹의 기준은 1. 행이 작은 순 2. 열이 작은 순

// 로직 순서
// 1. 크기가 가장 큰 블록 그룹을 찾는다
// (크기가 같다면 1. 무지개 블록수 많은 순 2. 블록 행이 큰 순 3. 열이 큰 순)
// 2. 해당 블록 그룹을 제거 (블록수^2 만큼의 점수 획득)
// 3. 중력: 검은색 블록(-1)을 제외한 모든 블록이 행의 번호가 큰 칸으로 이동
// 4. 반시계 90도 회전
// 5. 중력: 검은색 블록(-1)을 제외한 모든 블록이 행의 번호가 큰 칸으로 이동
// 6. 위의 과정들이 끝날 때까지 반복 후, 점수 출력

vector<pair<int, int> > findBlockGroup(int board[21][21], int x, int y) {
    queue<pair<int, int> > q;
    q.push({x, y});
    int color = board[x][y];
    visited[x][y] = 1;

    //cout << color << flush << "<<\n";

    vector<pair<int, int> > group;
    group.push_back({x, y});

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == -1 || board[nx][ny] == -2) continue; // 검은색 블록 포함 X
            if (board[nx][ny] != 0 // 무지개 블록이 아닌 동시에
                && board[nx][ny] != color)
                continue; // 다른 색깔이면 안됨
            if (visited[nx][ny]) continue;

            q.push({nx, ny});
            group.push_back({nx, ny});
            visited[nx][ny] = 1;
        }
    }

    return group;
}

pair<int,int> findStandardBlock(vector<pair<int,int>>& group, int board[21][21]) {
    pair<int,int> standard = {n, n};

    for (auto& p : group) {
        if (board[p.first][p.second] > 0) {
            if (p.first < standard.first ||
                (p.first == standard.first && p.second < standard.second)) {
                standard = p;
                }
        }
    }
    return standard;
}

void eraseBlocks(vector<pair<int, int> > blocks, int board[21][21]) {
    for (int i = 0; i < blocks.size(); i++) {
        board[blocks[i].first][blocks[i].second] = -2; // -2는 없는 상태.
    }

    score += (int) pow((int) blocks.size(), 2);
}

void gravity(int board[21][21]) {
    // 열 별로 블록 위치 계산
    for (int j = 0; j < n; j++) {
        // 마지막 행부터 시작
        for (int i = n - 1; i >= 0; i--) {
            // 빈 칸 발견 시에 내려올 블록 탐색
            if (board[i][j] == -2) {
                for (int k = i - 1; k >= 0; k--) {
                    // 검은색 블록이면 break
                    if (board[k][j] == -1) break;
                    if (board[k][j] != -2) {
                        board[i][j] = board[k][j];
                        board[k][j] = -2;
                        break;
                    }
                }
            }
        }
    }
}

void rotate(int board[21][21]) {
    int temp[21][21];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[n - 1 - j][i] = board[i][j];
        }
    }

    memcpy(board, temp, sizeof(temp));
}

int countRainbow(vector<pair<int, int> > &group, int board[21][21]) {
    int count = 0;
    for (auto &p: group) {
        if (board[p.first][p.second] == 0) count++;
    }
    return count;
}

void printBoard(int board[21][21]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int init[21][21];

    memcpy(init, board, sizeof(init));

    while (1) {
        // 1. 크기가 가장 큰 블록 그룹을 찾는다
        vector<pair<int, int> > maxGroup;
        int maxX = -1;
        int maxY = -1;
        int maxSize = -1;;
        int maxRainbow = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 검은색이면 continue
                if (init[i][j] == 0 || init[i][j] == -1 || init[i][j] == -2) continue;
                memset(visited, 0, sizeof(visited));
                vector<pair<int, int> > group = findBlockGroup(init, i, j);

                int rainbowCount = countRainbow(group, init);

                //cout << group.size() << " " << maxSize << "\n";

                int groupSize = group.size();
                if (groupSize < 2) continue;
                if (groupSize - rainbowCount <= 0) continue;

                pair<int,int> currentStandard = findStandardBlock(group, init);
                int sx = currentStandard.first;
                int sy = currentStandard.second;

                if (groupSize > maxSize ||
                    (groupSize == maxSize && rainbowCount > maxRainbow) ||
                    (groupSize == maxSize && rainbowCount == maxRainbow && sx > maxX) ||
                    (groupSize == maxSize && rainbowCount == maxRainbow && sx == maxX && sy > maxY)) {
                    maxGroup = group;
                    maxSize = groupSize;
                    maxX = sx;
                    maxY = sy;
                    maxRainbow = rainbowCount;

                }

                for (auto& p : group) {
                    if (init[p.first][p.second] == 0) {
                        visited[p.first][p.second] = 0;
                    }
                }
            }
        }

        // 2. 해당 블록들을 제거한다.
        eraseBlocks(maxGroup, init);
        
        // 3. 격자에 중력이 작용한다.
        gravity(init);
        
        // 4. 격자가 반시계 방향 90도 회전한다.
        rotate(init);
        
        // 5. 중력 다시한번 작용
        gravity(init);

        if (maxSize < 2) break;
    }

    cout << score;
}

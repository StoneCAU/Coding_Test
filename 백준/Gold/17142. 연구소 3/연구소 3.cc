#include <bits/stdc++.h>

using namespace std;

int n, m;
char arr[51][51];
int visited[51][51];
int cnt = -1;

vector<pair<int,int>> v;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(char temp[51][51], vector<int>& sel) {
    queue<pair<int,int>> q;

    for (int i=0;i<sel.size();i++) {
        int x = v[sel[i]].first;
        int y = v[sel[i]].second;

        q.push({x, y});
        temp[x][y] = '0';
        visited[x][y] = 1;
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny]) continue;
            if (temp[nx][ny] == '-') continue;
            if (temp[nx][ny] == '0' || temp[nx][ny] == '*') {
                q.push({nx, ny});
            }

            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }

    }
}

int check() {
    int maxTime = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (arr[i][j] == '.') {
                if (visited[i][j] == 0) return -1;
                maxTime = max(maxTime, visited[i][j] - 1);
            }
        }
    }

    return maxTime;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            int num;
            cin >> num;

            if (num == 0) arr[i][j] = '.'; // 이동 가능한 길
            else if (num == 1) arr[i][j] = '-'; // 벽
            else if (num == 2) {
                arr[i][j] = '0'; // 비활성 바이러스
                v.push_back({i,j});
            }
        }
    }

    // 바이러스 index 초기화
    vector<int> idx;
    for (int i=0;i<v.size();i++) {
        idx.push_back(i);
    }

    // 활성 바이러스 1~m개 선택
    for (int i=1;i<=m;i++) {
        vector<int> tmp;
        for (int j=1;j<=idx.size();j++) {
            if (j <= i) tmp.push_back(0);
            else tmp.push_back(1);
        }

        do {
            // visited 초기화
            memset(visited, 0, sizeof(visited));

            vector<int> sel;

            for (int j=0;j<tmp.size();j++) {
                if (tmp[j] == 0) sel.push_back(idx[j]);
            }

            // bfs 돌리기
            char temp[51][51];
            memcpy(temp, arr, sizeof(temp));

            bfs(temp, sel);

            // 결과 반영
            int res = check();
            if (res != -1) {
                if (cnt == -1) cnt = res;
                else cnt = min(cnt, res);
            }

        } while (next_permutation(tmp.begin(), tmp.end()));
    }

    cout << cnt;
}

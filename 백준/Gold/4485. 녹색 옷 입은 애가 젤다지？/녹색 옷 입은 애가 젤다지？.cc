#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int cnt = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    while (1) {
        cin >> n;
        if (!n) break;

        vector<vector<int>> arr(n, vector<int>(n));

        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cin >> arr[i][j];
            }
        }

        vector<vector<int>> lose(n, vector<int>(n, 99999999));
        lose[0][0] = arr[0][0];

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq; // 비용, x, y
        pq.push({lose[0][0],0,0});

        while (!pq.empty()) {
            auto [curLose, curX, curY] = pq.top();
            pq.pop();

            if (curLose > lose[curX][curY]) continue;

            for (int i=0;i<4;i++) {
                int nx = curX + dx[i];
                int ny = curY + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (curLose + arr[nx][ny] < lose[nx][ny]) {
                    lose[nx][ny] = curLose + arr[nx][ny];
                    pq.push({lose[nx][ny], nx, ny});
                }
            }
        }

        cout << "Problem " << cnt << ": " << lose[n-1][n-1] << "\n";
        cnt++;
    }
}
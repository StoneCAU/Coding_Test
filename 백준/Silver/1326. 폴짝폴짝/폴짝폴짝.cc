#include<bits/stdc++.h>

using namespace std;

int n;
int arr[10001];
int visited[10001];
int ans = -1;
int s, e;
int d[] = {-1, 1};

void bfs() {
    queue<pair<int, int>> q; // {번호, 갯수}
    q.emplace(s, 0);
    visited[s] = 1;

    while (!q.empty()) {
        int xx = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (xx == e) {
            ans = cnt;
            return;
        }

        for (int i=0;i<2;i++) {
            int nx = xx;
            int t = arr[xx];

            if (i == 0) {
                while (1) {
                    nx += t;

                    if (nx > n) break;
                    if (visited[nx]) continue;
                    visited[nx] = 1;
                    q.emplace(nx, cnt+1);
                }
            }
            else {
                while (1) {
                    nx -= t;

                    if (nx <= 0) break;
                    if (visited[nx]) continue;
                    visited[nx] = 1;
                    q.emplace(nx, cnt+1);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    cin >> s >> e;

    if (s == e) {
        cout << "-1";
        return 0;
    }

    bfs();

    cout << ans;
}
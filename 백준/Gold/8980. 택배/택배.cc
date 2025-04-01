#include <bits/stdc++.h>

using namespace std;

int n, c, m;
int t = 1;
int cur = 0;
int res = 0;
int idx = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c >> m;

    vector<tuple<int, int, int>> v;

    for (int i = 0; i < m; i++) {
        int s, e, b;

        cin >> s >> e >> b;

        v.push_back({e, s, b});
    }

    sort(v.begin(),v.end());

    // 트럭(도착번호, 박스 수)
    queue<tuple<int,int,int>> q;

    // 마을 번호
    for (int j=1;j<=n;j++) {

        // 배달
        while (!q.empty()) {
            auto [te, ts, tb] = q.front();

            // 배달 위치인 경우
            if (te == j) {
                cur -= tb;
                q.pop();

                res += tb;
            }
            else break;
        }

        for (int i = idx;i < m;i++) {
            auto [e, s, b] = v[i];

            // 시작 번호가 현재 번호보다 작으면 패스
            if (s < j) continue;

            // 더 담을 수 있으면 담는다.
            if (cur < c) {
                // 넘치는 경우
                if (cur + b >= c) {
                    int rest = c - cur;
                    rest = min(rest, b);

                    // 일부분 넣을 수 있으면 넣기
                    if (rest > 0) {
                        q.push({e, s, rest});
                        cur += rest;

                    }
                }
                // 널널하다면
                else if (cur + b < c) {
                    q.push(v[i]);
                    cur += b;
                }
            }
            else break;
        }
    }

    cout << res;
}

// TC1: 총 40 / 10(2) + 30(3) + 30(4)
// 1. 10(2) + 20(3)
// 2. 10(3) + 10(4)
// 3. 20(4) + 10(4)

// TC2: 총 60 / 30(2) + 60(5) + 60(6)
// 1. 30(2)
// 2. 60(5)
// 5. 60(6)
// 6. end
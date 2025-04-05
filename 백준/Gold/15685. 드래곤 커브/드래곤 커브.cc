#include <bits/stdc++.h>

using namespace std;

int n;
int arr[101][101];
int ans = 0;

// 오른쪽, 위, 왼쪽, 아래 (90도 돌 때마다 + 1)
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=0;i<n;i++) {
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        arr[y][x] = 1;

        vector<int> dir;

        // 0세대: 1
        // 1세대: 1 // 2
        // 2세대: 1, 2 // 3, 2 (원래 벡터 거꾸로 돌리고 +1 씩)
        // 3세대: 1, 2, 3, 2 // 3, 0, 3, 2
        dir.push_back(d);

        // 세대 만큼 반복
        for (int j=0;j<g;j++) {
            for (int k=dir.size()-1;k>=0;k--) {
                dir.push_back((dir[k] + 1) % 4);
            }
        }

        int nx = x;
        int ny = y;

        // 배열에 기록
        for (int j=0;j<dir.size();j++) {
            nx += dx[dir[j]];
            ny += dy[dir[j]];

            arr[ny][nx] = 1;
        }
    }

    // 갯수 카운트
    for (int y=0;y<100;y++) {
        for (int x=0;x<100;x++) {
            if (arr[y][x] && arr[y][x+1] && arr[y+1][x] && arr[y+1][x+1])
                ans++;
        }
    }

    cout << ans;

}

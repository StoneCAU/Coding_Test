#include <bits/stdc++.h>

using namespace std;

int n, m, h;
int cnt = 4;

// arr[h][i]: i번째 세로선을 통해서 h만큼의 depth에 위치할 때 이동해야하는 위치
// -1이면 이동 X
int arr[31][11];

// (1,1) = 2, (2,2) = -1, (2,3) = 3, (3,4)=-1, (3,5) = -1
bool check() {
    for (int start = 1;start<=n;start++) {
        int pos = start;

        for (int i=1;i<=h;i++) {
            if (arr[i][pos] != -1) {
                pos = arr[i][pos];
            }
        }

        if (pos != start) return false;
    }

    return true;
}

void dfs(int x, int depth) {
    if (depth >= cnt) return;

    if (check()) {
        cnt = depth;
        return;
    }

    for (int i = x; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (arr[i][j] != -1 || arr[i][j + 1] != -1) continue;
            
            arr[i][j] = j+1;
            arr[i][j+1] = j;

            dfs(i, depth+1);

            arr[i][j] = -1;
            arr[i][j+1] = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;

    memset(arr, -1, sizeof(arr));

    for (int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;

        arr[a][b] = b+1;
        arr[a][b+1] = b;
    }

    dfs(1,0);

    if (cnt >= 4) cout << -1;
    else cout << cnt;

}

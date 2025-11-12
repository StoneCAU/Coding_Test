#include <bits/stdc++.h>

using namespace std;

int n;
int board[101][101];
vector<vector<pair<int,int>>> blocks = {
    {{0,0}, {0,1}, {0,2}, {0,3}},
    {{0,0},{1,0},{2,0},{3,0}},

    {{0,0},{0,1},{1,1},{1,2}},
    {{0,0},{1,0},{1,-1},{2,-1}},

    {{0,0},{0,1},{0,2},{1,2}},
    {{0,0},{1,0},{2,0},{2,-1}},
    {{0,0},{1,0},{1,1},{1,2}},
    {{0,0},{1,0},{2,0},{0,1}},

    {{0,0},{0,1},{1,1},{0,2}},
    {{0,0},{1,0},{1,-1},{2,0}},
    {{0,0},{1,-1},{1,0},{1,1}},
    {{0,0},{1,0},{1,1},{2,0}},

    {{0,0},{0,1},{1,0},{1,1}}
};

bool isNotRange(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

int func() {
    int ans = INT_MIN;
    for (int x=0;x<n;++x) {
        for (int y=0;y<n;++y) {

            for (int i=0;i<blocks.size();++i) {
                int sum = 0;

                bool nope = false;
                for (int j=0;j<blocks[i].size();++j) {
                    int nx = x + blocks[i][j].first;
                    int ny = y + blocks[i][j].second;

                    if (isNotRange(nx,ny)) {
                        nope = true;
                        break;
                    }

                    sum += board[nx][ny];
                }

                if (!nope) {
                    ans = max(ans, sum);
                }
            }

        }
    }

    return ans;
}

// nxn 판이 있다.
// 5가지 종류의 블록을 판에 놓았을 때, 가장 많이 획득할 수 있는 점수는?
// 90도 회전 가능하다.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (1) {
        cin >> n;
        if (n == 0) break;

        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                cin >> board[i][j];
            }
        }

        int ans = func();

        cout << t++ << ". " << ans << "\n";
        cout.flush();
    }

}
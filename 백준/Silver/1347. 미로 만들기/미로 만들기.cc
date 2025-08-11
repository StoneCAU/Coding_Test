#include <bits/stdc++.h>

using namespace std;

int n;
vector<char> route;

int visited[102][102];

// 동, 서, 남, 북
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dir = 2;

void play() {
    // 첫 출발 {51, 51}
    visited[51][51] = 1;

    int x = 51, y = 51;

    for (int i=0;i<route.size();++i) {
        if (route[i] == 'F') {
            x += dx[dir];
            y += dy[dir];

            visited[x][y] = 1;
        }
        // 남 -> 서 -> 북 -> 동 -> 남
        else if (route[i] == 'R') {
            if (dir == 0) dir = 2;
            else if (dir == 1) dir = 3;
            else if (dir == 2) dir = 1;
            else dir = 0;
        }
        // 남 -> 동 -> 북 -> 서 -> 남
        else if (route[i] == 'L') {
            if (dir == 0) dir = 3;
            else if (dir == 1) dir = 2;
            else if (dir == 2) dir = 0;
            else dir = 1;
        }
    }
}

void print() {
    int mnx=INT_MAX, mny=INT_MAX;
    int mxx=INT_MIN, mxy=INT_MIN;

    for (int i=0;i<102;i++) {
        for (int j=0;j<102;j++) {
            if (visited[i][j]) {
                mnx = min(mnx, i);
                mxx = max(mxx, i);

                mny = min(mny, j);
                mxy = max(mxy, j);
            }
        }
        //cout << "\n";
    }

    // cout << mnx << " " << mny << "\n";
    // cout << mxx << " " << mxy << "\n";
     for (int i=mnx;i<=mxx;i++) {
            for (int j=mny;j<=mxy;j++) {
                if (visited[i][j]) cout << ".";
                else cout << "#";
            }
            cout << "\n";
        }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string str;
    cin >> str;
    for (int i=0;i<n;++i) {
        route.emplace_back(str[i]);
    }
    play();
    print();
}

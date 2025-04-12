#include <bits/stdc++.h>
using namespace std;

int n, m;
int sx, sy; // 메두사 위치
int ex, ey; // 공원 위치
vector<tuple<int, int, int>> warriors; // 전사들의 좌표 및 상태
vector<pair<int,int>> path;

int arr[51][51];
bool visited[51][51];
int dist[51][51];
bool attack[4][51][51]; // 상, 하, 좌, 우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void initAttack() {
    for (int i=0;i<4;i++) {
        for (int j=0;j<n;j++) {
            for (int k=0;k<n;k++) {
                attack[i][j][k] = false;
            }
        }
    }
}

void find(int ax, int ay) {
    initAttack();

    int tmp = 0;

    // 상
    for (int i=ax-1;i>=0;i--) {
        int start = ay-(tmp+1); // 2
        int end = ay+(tmp+1); // 3

        // 범위 설정
        if (start < 0) start = 0;
        if (end > n-1) end = n-1;

        for (int j=start;j<=end;j++) {
            attack[0][i][j] = true;
        }
        tmp++;
    }

    tmp = 0;

    // 하
    for (int i=ax+1;i<n;i++) {
        int start = ay-(tmp+1); // 
        int end = ay+(tmp+1);

        // 범위 설정
        if (start < 0) start = 0;
        if (end > n-1) end = n-1;

        for (int j=start;j<=end;j++) {
            attack[1][i][j] = true;
        }
        tmp++;
    }

    tmp = 0;

    // 좌
    for (int j=ay-1;j>=0;j--) {
        int start = ax-(tmp+1);
        int end = ax+(tmp+1);

        // 범위 설정
        if (start < 0) start = 0;
        if (end > n-1) end = n-1;

        for (int i=start;i<=end;i++) {
            attack[2][i][j] = true;
        }

        tmp++;
    }

    tmp = 0;

    // 우
    for (int j=ay+1;j<n;j++) {
        int start = ax-(tmp+1);
        int end = ax+(tmp+1);

        // 범위 설정
        if (start < 0) start = 0;
        if (end > n-1) end = n-1;
        
        for (int i=start;i<=end;i++) {
            attack[3][i][j] = true;
        }
        tmp++;
    }
}

int getMaxDirect() {
    int res = 0;
    int idx;

    int u = 0, d = 0, l = 0, r = 0;  // 각 방향별 공격받는 전사의 수
    vector<int> tmp;

    // warriors 벡터를 순회
    for (int a = 0; a < warriors.size(); a++) {
        // 각 전사의 x, y 좌표 가져오기
        auto& [x, y, status] = warriors[a];

        // 죽은 전사(1)는 카운팅에서 제외
        if (status == 1) continue; 

        // 방향별 공격받는 전사 수 계산
        for (int i = 0; i < 4; i++) {  // 4개의 방향에 대해 반복 (상, 하, 좌, 우)
            if (attack[i][x][y] == 1) {  // 공격받는 경우
                if (i == 0) u++;  // 상 방향
                else if (i == 1) d++;  // 하 방향
                else if (i == 2) l++;  // 좌 방향
                else if (i == 3) r++;  // 우 방향
            }
        }
    }

    tmp.push_back(u); tmp.push_back(d);
    tmp.push_back(l); tmp.push_back(r);

    // 각 방향별 공격받은 전사 수 중 최대값 구하기
    for (int i=0;i<4;i++) {
        if (res < tmp[i]) {
            res = tmp[i];
            idx = i;
        }
    }

    return idx;
}

void getSafeZone(int nx, int ny, int dir) {
    for (int i=0;i<warriors.size();i++) {
        auto [x, y, sts] = warriors[i];
        int tmp = 0;

        if (sts == 1) continue;
        if (!attack[dir][x][y]) continue;

        if (dir == 0) {
            if (y >= ny - 1 && y <= ny + 1) {
                    for (int j=x-1;j>=0;j--) {
                        attack[dir][j][y] = false;
                    } 
                
            }
            else {
                for (int j=x-1;j>=0;j--) {
                    int start;
                    int end;

                    if (y > ny) {
                        start = y;
                        end = y+(tmp+1);
                    }
                    else {
                        start = y-(tmp+1);
                        end = y;
                    }

                    // 범위 설정
                    if (start < 0) start = 0;
                    if (end > n) end = n;

                    for (int k=start;k<=end;k++) {
                        attack[dir][j][k] = false;
                    }
                    tmp++;
                }

                tmp = 0;
            }
        } 
        else if (dir == 1) {
            if (y >= ny - 1 && y <= ny + 1) {
                    for (int j=x+1;j<n;j++) {
                        attack[dir][j][y] = false;
                    } 
            }
            else {
                for (int j=x+1;j<n;j++) {
                    int start;
                    int end;

                    if (y > ny) {
                        start = y;
                        end = y+(tmp+1);
                    }
                    else {
                        start = y-(tmp+1);
                        end = y;
                    }

                    // 범위 설정
                    if (start < 0) start = 0;
                    if (end > n) end = n;

                    for (int k=start;k<=end;k++) {
                        attack[dir][j][k] = false;
                    }
                    tmp++;
                }

                tmp = 0;
            }
        }
        else if (dir == 2) {
            if (x >= nx - 1 && x <= nx + 1) {
                    for (int j=y-1;j>=0;j--) {
                        attack[dir][x][j] = false;
                    } 
            }
            else {
                for (int j=y-1;j>=0;j--) {
                    int start;
                    int end;

                    if (x > nx) {
                        start = x;
                        end = x+(tmp+1);
                    }
                    else {
                        start = x-(tmp+1);
                        end = x;
                    }

                    // 범위 설정
                    if (start < 0) start = 0;
                    if (end > n) end = n;

                    for (int k=start;k<=end;k++) {
                        attack[dir][k][j] = false;
                    }
                    tmp++;
                }

                tmp = 0;
            }
        }
        else if (dir == 3) {
            if (x >= nx - 1 && x <= nx + 1) {
                    for (int j=y+1;j<n;j++) {
                        attack[dir][x][j] = false;
                    } 
            }
            else {
                for (int j=y+1;j<n;j++) {
                    int start;
                    int end;

                    if (x > nx) {
                        start = x;
                        end = x+(tmp+1);
                    }
                    else {
                        start = x-(tmp+1);
                        end = x;
                    }

                    // 범위 설정
                    if (start < 0) start = 0;
                    if (end > n) end = n;

                    for (int k=start;k<=end;k++) {
                        attack[dir][k][j] = false;
                    }
                    tmp++;
                }

                tmp = 0;
            }
        }
    }
}

int getStoneCount(int dir) {
    int cnt = 0;

    for (int i=0;i<warriors.size();i++) {
        auto& [x, y, sts] = warriors[i];
        if (sts == 1) continue;

        if (attack[dir][x][y]) {
            sts = 2;
            cnt++;
        }
    } 

    return cnt;
}

int kill(int nx, int ny) {
    int cnt = 0;
    
    for (int i=0;i<warriors.size();i++) {
        auto& [x, y, sts] = warriors[i];
        if (sts == 1) continue;

        if (nx == x && ny == y) {
            sts = 1;
            cnt++;
        }
    } 

    return cnt;
}

int getDistance(int fx, int fy, int sx, int sy) {
    return abs(fx-sx)+abs(fy-sy);
}

int move(int mx, int my, int md) {
    int moved = 0;

    for (int i = 0; i < warriors.size(); i++) {
        auto& [x, y, status] = warriors[i];

        if (status != 0) continue; // 돌로 변했거나 죽은 전사는 이동 X

        //cout << i << " 원 위치: " << x << " " << y << "\n";

        // 첫 번째 이동: 상하좌우 우선순위
        int fx = x, fy = y;
        int minDist = getDistance(fx, fy, mx, my);
        bool firstMoved = false;

        int firstDir[] = {0, 1, 2, 3}; // 상하좌우

        for (int d = 0; d < 4; d++) {
            int nx = fx + dx[firstDir[d]];
            int ny = fy + dy[firstDir[d]];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (attack[md][nx][ny]) continue;

            int ndist = getDistance(nx, ny, mx, my);
            if (ndist < minDist) {
                fx = nx;
                fy = ny;
                minDist = ndist;
                firstMoved = true;
                //cout << i << " 첫 번째 이동: " << fx << " " << fy << "\n";
            }
        }

        // 첫 번째 이동 적용
        if (firstMoved) {
            moved++;
        }

        // 두 번째 이동: 좌우상하 우선순위
        int secondDir[] = {2, 3, 0, 1}; // 좌우상하
        bool secondMoved = false;

        for (int d = 0; d < 4; d++) {
            int nx = fx + dx[secondDir[d]];
            int ny = fy + dy[secondDir[d]];

                           // cout << dx[secondDir[d]] << " " << dy[secondDir[d]] <<"\n";


            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (arr[nx][ny] == 1) continue;
            if (attack[md][nx][ny]) continue;

            int ndist = getDistance(nx, ny, mx, my);
            if (ndist < minDist) {
                //cout << fx << " " << fy <<"\n";
                fx = nx;
                fy = ny;
                //cout << fx << " " << fy <<"\n";
                minDist = ndist;
                secondMoved = true;
            }
        }

        if (secondMoved) {
            moved++;
        }

        // 최종 위치 반영
        x = fx;
        y = fy;
        //cout << i << " 두 번째 이동: " << x << " " << y << "\n\n";

    }



    return moved;
}


void initSts() {
    for (int i=0;i<warriors.size();i++) {
        auto& [x,y,sts] = warriors[i];
        if (sts == 1) continue; // 죽음
        if (sts == 2) sts = 0; // 한 턴간 돌
        
    }
}

void printDebugInfo(int turn, int mx, int my, int md) {
    cout << "\n=== 턴 " << turn << " ===\n";
    cout << "메두사 위치: (" << mx << ", " << my << ")\n";

    cout << "전사 위치들:\n";
    for (int i = 0; i < warriors.size(); i++) {
        auto [x, y, status] = warriors[i];
        string state = (status == 0 ? "정상" : (status == 1 ? "죽음" : "돌"));
        cout << " - 전사 " << i << ": (" << x << ", " << y << "), 상태: " << state << "\n";
    }

    cout << "\n맵 상태:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == mx && j == my) cout << "M "; // 메두사
            else {
                bool isWarrior = false;
                for (auto [wx, wy, status] : warriors) {
                    if (status == 0 && wx == i && wy == j) {
                        cout << "W ";
                        isWarrior = true;
                        break;
                    }
                }
                if (isWarrior) continue;

                if (arr[i][j] == 1) cout << "# "; // 벽
                else if (attack[md][i][j]) cout << "* "; // 메두사 시야
                else cout << ". "; // 빈 공간
            }
        }
        cout << "\n";
    }
    cout << "==============\n";
}

vector<pair<int,int>> findShortestPath(int sx, int sy, int ex, int ey) {
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    pair<int,int> prev[51][51]; // 각 위치로 오기 직전 위치 저장

    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (x == ex && y == ey) break;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (arr[nx][ny] == 1) continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            prev[nx][ny] = {x, y};
            q.push({nx, ny});
        }
    }

    // 경로 추적
    vector<pair<int,int>> path;
    if (dist[ex][ey] == -1) return path; // 길 없음

    int x = ex, y = ey;
    while (!(x == sx && y == sy)) {
        path.push_back({x, y});
        tie(x, y) = prev[x][y];
    }
    path.push_back({sx, sy});
    reverse(path.begin(), path.end());

    return path;
}


void bfs() {
    for (int k=1;k<path.size();k++) {
        int nx = path[k].first;
        int ny = path[k].second;

        // 메두사가 공원에 도착했다
        if (nx == ex && ny == ey) {
            cout << 0;
            return;
        }

        for (int j=0;j<warriors.size();j++) {
            auto& [x,y,sts] = warriors[j];

            if (x == nx && y == ny) sts = 1; // 죽음 처리
        }

        // 메두사 현재 위치 기반 공격 범위 찾기
        find(nx, ny);

        // 전사들이 많은 방향 바라보기
        int nd = getMaxDirect();
                
        // if (k > 2) {
        //     cout << "\n";
        //         for (int a=0;a<n;a++) {
        //             for (int b=0;b<n;b++) {
        //                 cout << attack[nd][a][b] << " ";
        //             }
        //             cout << "\n";
        //         }
        //         }

        //         // 전사 위치에 따라 안전한 위치 구분하기
                 getSafeZone(nx, ny, nd);

        //         if (k > 2) {
        //             cout << nx << " " << ny << "\n";
        //         cout << "\n";
        //         for (int a=0;a<n;a++) {
        //             for (int b=0;b<n;b++) {
        //                 cout << attack[nd][a][b] << " ";
        //             }
        //             cout << "\n";
        //         }
        //         }


                // 돌로 변한 전사의 수 구하기
                int cnt = getStoneCount(nd);


                // 전사들의 이동 수 구하기
                int mCnt = move(nx,ny,nd);

                // 죽은 전사 계산
                int killed = kill(nx, ny);

               // if (k > 3) printDebugInfo(1, nx, ny, nd);

                initSts();

                // 출력
                cout << mCnt << " " << cnt << " " << killed << "\n";
    }
}

int main() {
    cin >> n >> m;

    cin >> sx >> sy >> ex >> ey;

    for (int i=0;i<m;i++) {
        int x,y;
        cin >> x >> y;

        warriors.push_back({x,y,0});
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    path = findShortestPath(sx,sy,ex,ey);

    // for (int i=0;i<path.size();i++) {
    //     int x = path[i].first;
    //     int y = path[i].second;

    //     cout << x << " " << y << "\n";
    // }

    if (path[path.size()-1].first != ex || path[path.size()-1].second != ey)
    {
        cout << -1;
        return 0;
    }

    bfs();


}
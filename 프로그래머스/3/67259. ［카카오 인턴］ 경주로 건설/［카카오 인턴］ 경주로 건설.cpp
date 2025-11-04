#include<bits/stdc++.h>

using namespace std;

// 상 하 좌 우
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int dp[26][26][4]; // {x,y,dir}
int answer = INT_MAX;

int solution(vector<vector<int>> board) {
    int n = board.size();
    fill(&dp[0][0][0], &dp[0][0][0] + 26 * 26 * 4, INT_MAX);
    queue<tuple<int,int,int,int>> q; // {x,y,dir,cost}
    
    // 첫 이동은 오른쪽 or 아래쪽
    q.emplace(0,0,1,0);
    q.emplace(0,0,3,0);
    
    while (!q.empty()) {
        auto [x, y, dir, cost] = q.front(); q.pop();
        
        if (x == n-1 && y == n-1) {
            answer = min(answer, cost);
            continue;
        }
        
        for (int i=0;i<4;++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == 1) continue;
            
            int nc = cost + ((dir == i) ? 100 : 600);
            
            if (nc < dp[nx][ny][i]) {
                dp[nx][ny][i] = nc;
                q.emplace(nx,ny,i,nc);
            }
        }
    }
    
    return answer;
    
}
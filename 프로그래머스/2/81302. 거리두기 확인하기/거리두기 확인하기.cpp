#include<bits/stdc++.h>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int getMHT(int r1, int c1, int r2, int c2) {
    return abs(r1-r2) + abs(c1-c2);
}

bool bfs(vector<string> room, int x, int y) {
    int n = room.size();
    queue<tuple<int,int,int>> q;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    
    q.push({x, y, 0});
    visited[x][y] = 1;
    
    while(!q.empty()) {
        auto [xx, yy, dist] = q.front();
        q.pop();
        if (dist >= 2) continue;

        for (int i=0;i<4;i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
        
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny]) continue;
            if (room[nx][ny] == 'X') continue;            
            if (room[nx][ny] == 'P') return false;

            q.push({nx, ny, dist+1});  
            visited[nx][ny] = 1;
            
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i=0;i<places.size();i++) {
        vector<string> room = places[i];
        bool prevent = true;;
        
        vector<pair<int,int>> p;
        for (int i=0;i<room.size();i++) {
            for (int j=0;j<room[i].length();j++) {
                if (room[i][j] == 'P') 
                    p.push_back({i, j});
            }
        }
        
        for (auto a : p) {
            int x = a.first;
            int y = a.second;
            
            if (!bfs(room,x,y)) {
                prevent = false;
                break;
            }
        }
        
        if (!prevent) answer.push_back(0);
        else answer.push_back(1);
    }
    
    return answer;
}
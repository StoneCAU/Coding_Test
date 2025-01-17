#include<vector>
#include<queue>
#include<iostream>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

queue<pair<int,int>> q;

int bfs(vector<vector<int>> maps) {
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(),0));

    q.push({0,0});
    visited[0][0] = 1;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
                
        for (int i=0;i<4;i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if (xx < 0 || xx >= maps.size() || yy < 0 || yy >= maps[0].size()) continue;
            if (visited[xx][yy]) continue;
            if (!maps[xx][yy]) continue;
            visited[xx][yy] = visited[x][y] + 1;
            if (xx == maps.size() - 1 && yy == maps[0].size() - 1) {
                return visited[xx][yy];
            }
            q.push({xx, yy});
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = bfs(maps);
    
    return answer;

}
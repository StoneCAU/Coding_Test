#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> graph(201);
vector<int> visited(201);
int count = 0;

void bfs(int a) {
    if (visited[a]) return;
    
    count++;
    
    queue<int> q;
    q.push(a);
    visited[a] = 1;
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        
        for(int i=0;i<graph[x].size();i++) {
            int xx = graph[x][i];
            
            if (visited[xx]) continue;
            visited[xx] = 1;
            q.push(xx);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
        
    for (int i=0;i<computers.size();i++) {
        for(int j=0;j<n;j++) {
            if (i == j) continue;
            if(computers[i][j]) graph[i].push_back(j); 
        }
    }
    
    for(int i=0;i<n;i++) {
        bfs(i);
    }
    
    return count;
}
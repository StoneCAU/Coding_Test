#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int bfs(int num, vector<vector<int>> graph) {
    vector<int> visited(101, 0);
    int count = 1;    
    queue<int> q;
    
    q.push(num);
    visited[num] = 1;
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (int i=0;i<graph[x].size();i++) {
            int xx = graph[x][i];
            if (visited[xx]) continue;
            q.push(xx);
            visited[xx] = 1;
            count++;
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000000000;
    
    // 순서대로 컷
    for (int i=0;i<wires.size();i++) {
        // 그래프 생성
        vector<vector<int>> graph(101);
    
        for(int j=0;j<wires.size();j++) {
            // 컷 할꺼만 제외하고 생성
            if (i == j) continue;
            
            graph[wires[j][0]].push_back(wires[j][1]);
            graph[wires[j][1]].push_back(wires[j][0]);
        }
        
        int first = bfs(wires[i][0], graph);
        int second = n - first;
        
        answer = min(answer, abs(first-second));
    
    }
    
    return answer;
}
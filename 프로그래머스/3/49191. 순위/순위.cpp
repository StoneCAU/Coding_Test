#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    
    for (int i=0;i<results.size();++i) {
        int win = results[i][0], lose = results[i][1];
        graph[win][lose] = 1;
        graph[lose][win] = -1;
    }
    
    for (int k=1;k<=n;++k) {
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                if (graph[i][k] == 1 && graph[k][j] == 1) {
                    graph[i][j] = 1;
                }
                
                if (graph[i][k] == -1 && graph[k][j] == -1) {
                    graph[i][j] = -1;
                }
            }
        }
    }
    
    int answer = 0;
    for (int i=1;i<=n;++i) {
        int known = 0;
        for (int j=1;j<=n;++j) {
            if (graph[i][j] != 0) known++;
        }
        if (known == n-1) answer++;
    }
    
    return answer;
}
#include<bits/stdc++.h>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<pair<int,int>>> adj(N+1);
    
    for (int i=0;i<road.size();++i) {
        int a = road[i][0], b = road[i][1], c = road[i][2];
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    
    vector<int> dist(N+1, INT_MAX);
    dist[1] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // {dist, node}
    pq.emplace(0, 1);
    
    while (!pq.empty()) {
        auto [cost, now] = pq.top(); pq.pop();
        
        if (cost < dist[now]) continue;
        
        for (auto [next, w] : adj[now]) {
            int nxtCost = cost + w;
            if (nxtCost < dist[next]) {
                dist[next] = nxtCost;
                pq.emplace(nxtCost, next);
            }
        }
    }
    
    for (int i=1;i<=N;++i) {
        if (dist[i] <= K) answer++;
    }

    return answer;
}
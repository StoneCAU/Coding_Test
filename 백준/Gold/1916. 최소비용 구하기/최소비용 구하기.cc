#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<pair<int,int>> v[n+1];

    for (int i=0;i<m;i++) {
        int s,e,w;
        cin >> s >> e >> w;

        v[s].push_back({e, w}); // (도착점, 가중치)
    }

    int ts, te;
    cin >> ts >> te;

    vector<int> dist(n+1, 1000000000);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, ts});
    dist[ts] = 0;

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int curNode = pq.top().second;

        pq.pop();

        if (curDist > dist[curNode]) continue;

        for (auto edge : v[curNode]) {
            int nextNode = edge.first;
            int weight = edge.second;

            if (dist[curNode] + weight < dist[nextNode]) {
                dist[nextNode] = dist[curNode] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    cout << dist[te];
}
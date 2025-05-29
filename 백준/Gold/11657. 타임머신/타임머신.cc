#include <bits/stdc++.h>
using namespace std;

const int INF = int(1e9);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges;
    for (int i=0;i<m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }

    vector<long long> dist(n+1, INF);

    dist[1] = 0;

    for (int i=1;i<=n - 1;i++) {
        bool update = false;
        for (auto edge : edges) {
            auto [u,v,cost] = edge;

            if (dist[u] != INF && dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                update = true;
            }
        }

        if (!update) break;
    }

    bool hasNegative = false;
    for (auto edge : edges) {
        auto [u, v, cost] = edge;

        if (dist[u] != INF && dist[u] + cost < dist[v]) {
            hasNegative = true;
            break;
        }
    }

    if (hasNegative) {
        cout << -1 << "\n";
    }
    else {
        for (int i=2;i<=n;i++) {
            if (dist[i] == INF) cout << "-1\n";
            else cout << dist[i] << "\n";
        }
    }
}
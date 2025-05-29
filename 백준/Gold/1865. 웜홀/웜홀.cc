#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n, m, w;
        cin >> n >> m >> w;

        vector<tuple<int, int, int>> edges;

        for (int i = 0; i < m; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }

        for (int i = 0; i < w; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        vector<long long> dist(n + 1, 0); 
        
        bool hasNegative = false;

        for (int i = 1; i <= n - 1; ++i) { 
            bool update = false; 

            for (auto edge : edges) { 
                auto [u, v, cost] = edge;

                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    update = true;
                }
            }
            if (!update) break; 
        }

        for (auto edge : edges) { 
            auto [u, v, cost] = edge;

            if (dist[u] + cost < dist[v]) {
                hasNegative = true;
                break; 
            }
        }

        if (hasNegative) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
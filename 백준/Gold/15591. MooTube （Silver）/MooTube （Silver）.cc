#include <bits/stdc++.h>

using namespace std;

int N, Q;
vector<pair<int, int>> graph[5001]; 
bool visited[5001];

int dfs(int curr, int k, int minUsado) {
    visited[curr] = true;
    int count = 0;
    
    for (auto& edge : graph[curr]) {
        int next = edge.first;
        int usado = edge.second;
        
        if (visited[next]) continue;
        
        int newMin = min(minUsado, usado);
        
        if (newMin >= k) {
            count++;
            count += dfs(next, k, newMin);
        }
    }
    
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;

    for (int i = 0; i < N - 1; ++i) {
        int p, q, r;
        cin >> p >> q >> r;

        graph[p].push_back({q, r});
        graph[q].push_back({p, r});
    }

    for (int i = 0; i < Q; ++i) {
        int k, v;
        cin >> k >> v;
        
        fill(visited, visited + N + 1, false);
        
        int ans = dfs(v, k, INT_MAX);
        
        cout << ans << '\n';
    }
    
    return 0;
}
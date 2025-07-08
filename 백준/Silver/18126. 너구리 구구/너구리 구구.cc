#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<pair<int,long long>>> graph(5001);
bool visited[5001];
long long maxDist = 0;

void dfs(int cur, long long dist) {
    visited[cur] = true;
    if (maxDist < dist) maxDist = dist;

    for (int i=0;i<graph[cur].size();i++) {
        int next = graph[cur][i].first;
        long long weight = graph[cur][i].second;

        if (!visited[next]) {
            dfs(next, dist + weight);
        }
    }
}

// 1~n 까지의 방이 있다
// 입구는 1번으로 들어가야한다
// 최대한 먼 방에 아이스크림을 숨길거임
// 이동거리는 얼마?
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // 초기화
    for (int i=0;i<n-1;i++) {
        int a,b,c;
        cin >> a >> b >> c;

        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    dfs(1, 0);

    cout << maxDist;
}
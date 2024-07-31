#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool visited[101] = { 0, };
int graph[101][101];
int cnt = 0;

int n, m;

void dfs(int x)
{
    cnt++;
    visited[x] = true;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && graph[x][i]) dfs(i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    dfs(1);
    cout << cnt - 1;

}

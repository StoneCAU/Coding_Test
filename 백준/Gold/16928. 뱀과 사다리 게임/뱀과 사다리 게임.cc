#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m;
int board[102];
int visited[102];

queue<int> q;

void bfs()
{
	q.push(1);

	while (!q.empty())
	{
		if (visited[100]) return;

		int x = q.front();

		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int nx = x + i;

			if (nx > 100) continue;
			if (visited[nx]) continue;
			if (board[nx] > 0)
			{
				if (visited[board[nx]]) continue;
				q.push(board[nx]);
				visited[board[nx]] = visited[x] + 1;	
				visited[nx] = -1;

			}
			else
			{
				q.push(nx);
				visited[nx] = visited[x] + 1;
			}
		}
	}
}

// 1 -> 7 -> 99 -> 100

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int x, y;

		cin >> x >> y;

		board[x] = y;

	}

	for (int i = 0; i < m; i++)
	{
		int u, v;

		cin >> u >> v;

		board[u] = v;
	}

	bfs();

	cout << visited[100];
	

}
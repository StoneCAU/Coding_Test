#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;
char board[51][51];
int water[51][51];
int visited[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int M = 0;

queue<tuple<int, int, int>> q;

void bfs(int x, int y)
{
	fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

	q.push({ x,y, 0 });

	visited[x][y] = 1;

	while (!q.empty())
	{
		int xx = get<0>(q.front());
		int yy = get<1>(q.front());
		int len = get<2>(q.front());

		if (len > M) M = len;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 'W') continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = 1;
			q.push({ nx, ny, len + 1 });

		}
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < m; j++)
		{
			board[i][j] = s[j];
			if (s[j] == 'W') water[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (water[i][j]) continue;

			bfs(i, j);
			
		}
	}
	
	cout << M;
}



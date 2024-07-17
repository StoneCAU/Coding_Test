#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int k, w, h;
int board[202][202];
int visited[202][202][32];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int hx[] = { -1,-2,-1,-2,1,2,1,2 };
int hy[] = { -2,-1,2,1,-2,-1,2,1 };

queue<tuple<int, int, int>> q;

int bfs()
{
	q.push({ 0,0,0 });

	//visited[0][0][0] = 1;

	while (!q.empty())
	{
		int xx = get<0>(q.front());
		int yy = get<1>(q.front());
		int jump = get<2>(q.front());

		q.pop();

		if (xx == h - 1 && yy == w - 1) return visited[xx][yy][jump];

		if (jump < k)
		{
			for (int i = 0; i < 8; i++)
			{
				int nx = xx + hx[i];
				int ny = yy + hy[i];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (board[nx][ny]) continue;
				if (visited[nx][ny][jump+1]) continue;
				visited[nx][ny][jump+1] = visited[xx][yy][jump] + 1;

				//cout << nx << " " << ny << "\n";

				q.push({ nx, ny, jump + 1});
			}
		}
		
		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (board[nx][ny]) continue;
			if (visited[nx][ny][jump]) continue;
			visited[nx][ny][jump] = visited[xx][yy][jump] + 1;

			//cout << nx << " " << ny << "\n";

			q.push({ nx, ny, jump});
		}
		
	}

	return -1;
}

int main() {

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> k >> w >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> board[i][j];
		}
	}
	
	cout << bfs();

	
}
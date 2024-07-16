#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int n;
int board[101][101];
int check[101][101];
int visited[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int cnt = 0;
int m = 10000;
int res;

vector<pair<int, int>> v;
queue<pair<int, int>> q;

void bfs(int x, int y)
{
	q.push({ x, y });

	check[x][y] = cnt;

	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (check[nx][ny]) continue;
			if (!board[nx][ny]) continue;
			q.push({ nx, ny });
			check[nx][ny] = cnt;
		}
	}
}

void island() {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check[i][j] || !board[i][j]) continue;
			cnt++;
			bfs(i, j);
		}
	}

}

void minFind(int x, int y)
{
	q.push({ x, y });

	visited[x][y] = 1;

	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();
		//cout << "pop: " << xx << " " << yy << "\n";

		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visited[nx][ny]) continue;
			if (xx == x & yy == y) visited[nx][ny] = 1;
			else visited[nx][ny] = visited[xx][yy] + 1;
			if (check[x][y] != check[nx][ny] && check[nx][ny] > 0) {
				//cout << x << " " << y << "\n";
				res = --visited[nx][ny];
				return;
			}
			q.push({ nx, ny });
			//cout << "push: " << nx << " " << ny << "\n";
		}
	}

	
}


int main() {

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j]) v.push_back({ i, j });
		}
	}

	island();

	for (int k = 1; k <= cnt; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (check[i][j] != k) continue;
				while (!q.empty()) q.pop();
				//cout << "bfs: " << k << " " << i << " " << j << "\n";
				minFind(i, j);
				fill(&visited[0][0], &visited[0][0] + 101*101, 0);
				if (m > res) m = res;
			}
		}

		//cout << "\n";
	}

	cout << m;
}
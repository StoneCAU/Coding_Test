#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int m, n, k;
int area[101][101];
int visited[101][101];
int checked[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

queue<pair<int, int>> q;
vector<int> res;

void coloring(int sx, int sy, int ex, int ey) {
	for (int i = sy; i < ey; i++)
	{
		for (int j = sx; j < ex; j++)
		{
			visited[i][j] = 1;
		}
	}
}

void bfs(int x, int y) 
{

	int num = 1;

	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (checked[nx][ny]) continue;
			if (visited[nx][ny]) continue;

			q.push({ nx, ny });
			checked[nx][ny] = 1;
			num++;
		}
	}

	res.push_back(num);

}


int main() {

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int startX, endX;
		int startY, endY;
		
		cin >> startX >> startY >> endX >> endY;

		coloring(startX, m-endY, endX, m-startY);
	}

	vector<pair<int,int>> s;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] || checked[i][j]) continue;
			s.push_back({ i, j });
			bfs(i, j);
		}
	}

	cout << res.size() << "\n";

	sort(res.begin(), res.end());
	
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}

}
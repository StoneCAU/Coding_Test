#include <bits/stdc++.h>

using namespace std;

int n;
int area[101][101];
int check[101][101];
int m = 0;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int res = 0;

queue<pair<int,int>> q;

void bfs(int k, int x, int y)
{
	q.push({ x, y });

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
			if (area[nx][ny] <= k) continue;
			if (check[nx][ny]) continue;

			check[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> area[i][j];

			if (m < area[i][j]) m = area[i][j];
		}
	}


	for (int i = 0; i < m; i++)
	{

		int temp = 0;

		fill(&check[0][0], &check[0][0] + 101*101, 0);

		vector<pair<int, int>> v;

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (area[j][k] > i) v.push_back({ j, k });
			}
		}

		for (int j = 0; j < v.size(); j++)
		{
			int x = v[j].first;
			int y = v[j].second;

			if (check[x][y]) continue;
			bfs(i, x, y);
			temp++;
		}

		if (temp > res) res = temp;
	}

	cout << res;

}